#include<iostream>
#include"reclists.hpp"
#include"solutions.hpp"

using namespace std;

int main()
{

    std::cout << "Starting main..." << std::endl;
    list p;

    //test variables
    list q;
    bool testBool;

    //cout << "Enter a list to counts the number of atoms in it: ";
    //p = read_list();
    //q = read_list();

    //cout << "The list has " << numAtomsAtTheTopLevel(p) << " atoms at the top level.\n";
    // Write the code for each function, test it thoroughly, and then comment
    // it out and move to the next function.

    /*TEST FOR SMEMBER FUNCTION
    testBool = smember(p, q);
    cout << testBool << endl;
     */

    cout << "Test for is_Lat:\n";
    p = read_list();
    testBool = is_lat(p);
    cout << testBool;
    cout << "\n\n";




    /*TEST FOR AREEQUAL
    testBool = areEqual(p, q);
    cout << testBool;
     */

    cout << "Test for Member:\n";
    p = read_list();
    q = read_list();
    testBool = member(p, q);
    cout << testBool << endl;
    cout << "\n\n";



    cout << "Test for Last:\n";
    p = read_list();
    cout << last(p)->atom;
    cout << "\n\n";


    cout << "Test for list_pair: \n";
    p = read_list();
    q = read_list();
    write_list(list_pair(p, q));
    cout << "\n\n";


    cout << "Test for firsts: \n";
    p = read_list();
    write_list(firsts(p));
    cout << "\n\n";


    cout << "Tet for flat: \n";
    p = read_list();
    write_list(flat(p));
    cout << "\n\n";



    cout << "Test for two_the_same:\n";
    p = read_list();
    q = read_list();
    testBool = two_the_same(p, q);
    cout << testBool << endl;
    cout << "\n\n";





    cout << "Test for equal: \n";
    p = read_list();
    q = read_list();
    testBool = equal(p, q);
    cout << testBool;
    cout << "\n\n";



    cout << "Test for total_reverse:\n";
    p = read_list();
    write_list(total_reverse(p));
    cout << "\n\n";



    cout << "Test for shape: \n";
    p = read_list();
    write_list(shape(p));
    cout << "\n\n";



    cout << "Test for interesection: \n";
    p = read_list();
    q = read_list();
    write_list(intersection(p, q));
    cout << "\n\n";


    cout << "Test for list_union:\n";
    p = read_list();
    q = read_list();
    write_list(list_union(p, q));




    return 0;
}
