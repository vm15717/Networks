#include <iostream>
#include <Eigen/Dense>

int main()
{
    Eigen::Matrix3f A;
    A << 1, 2, 3,
         0, 1, 4,
         5, 1, 1;
    Eigen::Matrix3f A_inv = A.inverse();
    std::cout << A << std::endl;
    std::cout << A_inv << std::endl;
    return 0;
}