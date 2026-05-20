#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>

double condA(const Eigen::MatrixXd& A)
{
  Eigen::JacobiSVD<Eigen::MatrixXd> svd(A);
  Eigen::VectorXd singularValuesA=svd.singularValues();
  return singularValuesA.maxCoeff()/singularValuesA.minCoeff();
}

int main()
{
  const double tol=1.0e-15;
  unsigned int n=5;
  Eigen::MatrixXd B=Eigen::MatrixXd::Random(n,n); /* matrice casuale */
  /* controllo se invertibile */
  if (std::abs(B.determinant())<tol) {
    return -1;
  }
  Eigen::MatrixXd A=B.transpose()*B; /* matrice simmetrica def positiva */
  Eigen::VectorXd x_ex=Eigen::VectorXd::Ones(n); /* soluzione esatta */
  Eigen::VectorXd b=A*x_ex; /* termine noto */
  Eigen::VectorXd x=Eigen::VectorXd::Zero(n); /* soluzione iniziale */
  Eigen::VectorXd res=b-A*x; /* residuo iniziale */
  Eigen::VectorXd p=res; /* direzione iniziale */
  double res_norm_0=res.norm();
  const unsigned int it_max=10000;
  unsigned int it=0;
  const double res_tol=1.0e-12;
  std::cout.precision(2);
  std::cout<< std::scientific << "Numero di condizionamento della matrice: " << condA(A) << std::endl;
  while(it<it_max && res.norm()>res_tol*res_norm_0) {
	double alpha_k=((p.transpose()*res)/(p.transpose()*A*p)).value(); /* alpha_k */
    x=x+alpha_k*p;
    Eigen::VectorXd res_new=res-alpha_k*A*p; /* nuovo residuo */
	double beta_k=((p.transpose()*A*res_new)/(p.transpose()*A*p)).value(); /* beta_k */
	p=res_new-beta_k*p; /* nuova direzione coniugata */
	res=res_new; /* aggiorno residuo */
	it=it+1;
  }
  double err_rel=(x-x_ex).norm()/x_ex.norm(); /* errore relativo */
  std::cout.precision(4);
  std::cout<< std::scientific << "Iterazioni: " << it << "/" << it_max << std::endl;
  std::cout<< std::scientific << "Residuo relativo: " << res.norm()/res_norm_0 << std::endl;
  std::cout<< std::scientific << "Errore relativo: " << err_rel << std::endl;
  std::cout<< std::scientific << "Soluzione calcolata:\n" << x << std::endl;
  std::cout<< std::scientific << "Soluzione esatta:\n" << x_ex << std::endl;
  
  return 0;
}