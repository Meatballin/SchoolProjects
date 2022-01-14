#ifndef __MYSOLUTION_HPP
#define __MYSOLUTION_HPP

#include<iostream>
#include"reclists.hpp"

int numAtoms(list p);
int numAtomsAtTheTopLevel(list p);
bool areEqual(list p, list q);
bool is_lat(list p);
bool smember(list p, list q);
bool member(list p, list q);
list last(list p);
list list_pair(list p, list q);
list firsts(list p);
list flat(list p);
bool two_the_same(list p, list q);
bool equal(list p, list q);
list total_reverse(list p);
list shape(list p);
list intersection(list p, list q);
list list_union(list p, list q);


// p is an atom
// repeatAtom builds a list that contains n copies of p.
//repeatAtom( a, 5) returns (a a a a a)
//repeatAtom( a, 0) returns ()
list repeatAtom(list p, int n);

list append(list p, list q);

//p is not an atom
//sreverse reverses the components of p at the top level
//(a b c)
//     (c b a)
//(a (b c) (e f) g)
//   (g (e f) (b c) a)
list sreverse(list p);


#endif
