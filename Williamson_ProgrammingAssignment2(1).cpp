//Programming Assignment 2 - Implement Google's Page Rank
//by Yvette Williamson


#include<iomanip>
#include <iostream>
#include <string>
#include <set>

using namespace std;

class Graph {
	//class to build graph

	//intialization and declaration of variables
	const static int VERTICES = 100;
	double impGraph[VERTICES][VERTICES];
	bool directed;

public:

	Graph() {
	//Constructor

		directed = true;

	}

	void insert(int fromto, int tofrom) {
	//method to insert edges
		impGraph[fromto][tofrom] = 1;

	}

	void rank(int& a, int size, int he)
	{
	//method gives number of outedges a vertice has to calculate rank

		//intialization and declaration of variables
		a = 0;
		int occur = 0;

		for (int rr = 0; rr < size; rr++) {
			if (impGraph[he][rr] >= 1) {
				a++;

			}

		}


	}
	void pagerank(double arr[], int size, int iter) {
	//method to do page rank for each vertice

		//intialization and declaration of variables
		double r = 0.0;
		double q = 0.0;
		int he = 0;
		int occur = 0;
		int itcount = 1;
		int gr = 0;
		//temp array
		double* ear = new double[size];

		//intialize temp array
		for (int gu = 0; gu < size; gu++)
		{
			ear[gu] = 0;

		}

		//while loop to keep track of iterations
		while (itcount < iter) {

			for (int h = 0; h < size; h++) {

				//method to get out-going edges
				rank(occur, size, h);

				for (int rr = 0; rr < size; rr++) {

					if (impGraph[h][rr] == 1 && occur >= 1) {

						impGraph[h][rr] = 1.00 / occur;

					}
				}
			}

			//for loops to do matrix multiplication
			for (int h = 0; h < size; h++) {
				gr = 0;

				for (int rr = 0; rr < size; rr++) {

					if (impGraph[rr][h] >= 0) {

						r = impGraph[rr][h];

						q = arr[gr];

						r = r * q;

						ear[h] = ear[h] + r;

					}
					gr++;
				}
			}

			//new 1D array is copied and temp is emptied
			for (int sh = 0; sh < size; sh++)
			{
				arr[sh] = ear[sh];
				ear[sh] = 0;

			}
			itcount++;
		}


	}
};
int verticescheck(string check[100], string vertice, int& jj)
{
//method to get vertices names

	//intialization and declaration of variables
	int place = 0;
	int u = 0;

	//for loop to check if vertice name is in list or not
	for (int k = 0; k < 100; k++) {
		if (check[k] == vertice)
		{

			return k;

		}

		else if (check[k] == "")
		{
			check[k] = vertice;
			jj++;
			return k;
		}

	}

	//return new array with names of vertices
	return place;
}

int printRank(string link, string check[100])
{
//method to give correct page rank to URL, returns rank of vertice

	for (int hgh = 0; hgh < 100; hgh++)
	{
		if (check[hgh] == link)
		{
			return hgh;
		}
	}
	return 0;
}
int main()
{
//set up graph, array for vertices, array for pageranks, and print out list of vertices and ranks correctly
//uses user input to assign and create what was mentioned in the comment above

	//intialization and declaration of variables
	string tofrom = "";
	string fromto = "";
	int iterations = 0;
	int edges = 0;
	int i = 0;
	bool bedge = false;
	int d = 0;
	int f = 0;
	int s = 0;
	int jj = 0;
	int vertices = 0;
	int right = 0;
	//sorts the vertices names alphabetically
	set<string> sort;
	//array for vertices
	string vertcheck[100] = {};

	//take in user input
	std::cin >> edges;
	std::cin >> iterations;

	//check for valid input
	if (iterations < 0) {
		return 0;
	}

	if (edges < 0)
	{
		return 0;
	}

	//graph is created
	Graph *graph = new Graph();

	//while loop to insert vertices and edges in graph
	while (i < edges) {
		std::cin >> fromto;
		std::cin >> tofrom;

		//set name of vertice to unique number/code
		f = verticescheck(vertcheck, fromto, jj);
		s = verticescheck(vertcheck, tofrom, jj);

		//insert edge
		graph->insert(f, s);

		i++;
	}

	//add vertices' names to get sorted
	for (auto rt : vertcheck)
	{
		sort.insert(rt);

	}

	//array to keep pageranks
	double*art = new double[jj];

	//for loop for 1D array for calculating
	for (int gg = 0; gg < jj; gg++) {
		art[gg] = 1.00 / jj;
	}

	//calculate pagerank of each vertice
	graph->pagerank(art, jj, iterations);

	int jk = 0;

	//print out the vertices in alphabetical order with pagerank
	for (auto rt : sort)
	{

		if (rt != "") {
			jk = printRank(rt, vertcheck);
			std::cout << rt << " " << setprecision(2) << fixed << art[jk] << "\n";
		}


	}

	//delete allocated array
	for (int tt = 0; i < jj; tt++)
	{
		delete[] art;
	}


	return 0;

}


