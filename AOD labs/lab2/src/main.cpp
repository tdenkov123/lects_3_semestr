#include <iostream>
#include <fstream>
#include <cmath>



int main(int argc, char** argv) {
	const double pi = 3.14159265359;
	const double density_air{ 1.2041 }, density_metal{ 7200 }, aero_coef{ 0.47 }, diameter{ 0.1 }, angle{ 45.0 * pi / 180.0 }, g_const{ 9.8 };
	double x1{ 0 }, x2{ 0 }, v1{ 1000 * cos(angle) }, v2{ 1000 * sin(angle) };
	const double k{ 0 };

	std::ofstream file;
	file.open("./file.csv");

	for (int h = 0; h < 155; h = h + 5) {
		if (h != 0) {
			double h_t{ h * 1.0 };
			double i_t{ h_t }, x1_t{ x1 }, x2_t{ x2 }, v1_t{ v1 }, v2_t{ v2 };
			double k1{ v1_t * h_t }, l1{ v2_t * h_t };
			double s1{ -k * sqrt(v1_t * v1_t + v2_t * v2_t) * v1_t * h_t };
			double q1{ (-k * sqrt(v1_t * v1_t + v2_t * v2_t) * v2_t - g_const) * h_t };
						
			x1_t += k1 / 2, x2_t += l1 / 2, v1_t += s1 / 2, v2_t += q1 / 2;
			double k2{ v1_t * h_t }, l2{ v2_t * h_t };
			double s2{ -k * sqrt(v1_t * v1_t + v2_t * v2_t) * v1_t * h_t };
			double q2{ (-k * sqrt(v1_t * v1_t + v2_t * v2_t) * v2_t - g_const) * h_t };

			x1_t = x1 + k2 / 2, x2_t = x2 + l2 / 2, v1_t = v1 + s2 / 2, v2_t = v2 + q2 / 2;
			double k3{ v1_t * h_t }, l3{ v2_t * h_t };
			double s3{ -k * sqrt(v1_t * v1_t + v2_t * v2_t) * v1_t * h_t };
			double q3{ (-k * sqrt(v1_t * v1_t + v2_t * v2_t) * v2_t - g_const) * h_t };

			x1_t = x1 + k3, x2_t = x2 + l3, v1_t = v1 + s3, v2_t = v2 + q3;
			double k4{ v1_t * h_t }, l4{ v2_t * h_t };
			double s4{ -k * sqrt(v1_t * v1_t + v2_t * v2_t) * v1_t * h_t };
			double q4{ (-k * sqrt(v1_t * v1_t + v2_t * v2_t) * v2_t - g_const) * h_t };

			x1_t = x1 + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
			x2_t = x2 + (l1 + 2 * l2 + 2 * l3 + l4) / 6.0;
			v1_t = v1 + (s1 + 2 * s2 + 2 * s3 + s4) / 6.0;
			v2_t = v2 + (q1 + 2 * q2 + 2 * q3 + q4) / 6.0;

			file << h << ';' << x1_t << ';' << x2_t << ';' << v1_t << ';' << v2_t << '\n';
		}
	}

	return 0;
}