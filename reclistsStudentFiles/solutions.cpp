#include "reclists.hpp"
#include "solutions.hpp"

// As you implement functions in this file, you should add the
// function-prototype to the solutions.hpp. The function-prototypes
// for append and reverse are already in solutions.hpp.


int numAtoms(list p)
{
    if( is_null(p) )
        return 0;
    return numAtoms(cdr(p)) + 1;
}


bool is_lat(list p)
{
    if(is_atom(p))
    {
        return false;
    }
    //if we are at end of list or are given an empty list, return true
    if(is_null(p))
    {
        return true;
    }
    //if we don't have an atom, return false
    if(!is_atom(car(p)))
    {
        return false;
    }
    return is_lat(cdr(p));
}

// 'p' is an atom, 'q' is a non-atomic list
// return true if p appears anywhere in q.
// if 'p' is not an atom or 'q' is not a non-atomic list, call is an error
bool member(list p, list q)
{

    // if we use function with a non-atomic list p, or an atom 'q', we exit out of program
    // with exit code 1
    if((!is_atom(p)) || (is_atom(q)))
    {
        exit(EXIT_FAILURE);
    }
    // if at end of list for q and haven't returned true, then p is not in q
    if(is_null(q))
    {
        return false;
    }

    // if we run into an atom, do a comparison of p and car(q)
    if(is_atom(car(q)))
    {
        // check if contents in p and q are equal. "eq" function uses strcmp
        if(eq(p, car(q)))
        {
            return true;
        }
        // recursive call if our comparison doesn't come back true at car(q)
       return member(p, cdr(q));

    }

    //Go deeper into list if the car(q) was a non-atomic list
    return member(p, car(q));

}

list last(list p)
{
    // Check if we are at end of the list
    if(is_null(cdr(p)))
    {
        // if node below isn't an atom, we need to traverse deeper into list
        if(!is_atom(car(p)))
        {
            // recursive call with node below previous as argument to function
            return last(car(p));
        }
        //only return the atom if we are at the last node deep in the list from cdr calls
        return car(p);
    }
    // this gets us to end of our list before doing anything
    return last(cdr(p));
}

list list_pair(list p, list q)
{
    if(is_null(p))
    {
        return null();
    }

    //append the cons of both atoms in the same position of 'p' and 'q', then traverse
    //both lists to the next element
    return cons(append((cons(car(p), null())), cons(car(q), null())), list_pair(cdr(p), cdr(q)));
}

list firsts(list p)
{
    if(is_null(p))
    {
        return null();
    }

    //when we get to end of list, our 'q' of cons will be null and we input
    //our car(car(p)) into that null and work our way back to the start inputting
    //remaining first values in
    return cons(car(car(p)), firsts(cdr(p)));
}

list flat(list p)
{
    if(is_null(p))
    {
        return p;
    }

    //if we hit an atom, keep it and go further into our list 'p'
    if(is_atom(car(p)))
    {
        return cons(car(p), flat(cdr(p)));
    }
    //if we don't have an atom, start by traversing down all the way, then
    //go to the right with cdr and append our atoms
    return append(flat(car(p)), flat(cdr(p)));
}

bool two_the_same(list p, list q)
{
   if(is_null(p))
   {
       return false;
   }
   //If we run into an atom, use "member" to search the entire list that 'q' is pointing to
   if(is_atom(car(p)))
   {
       if(member(car(p) ,q))
       {
           return true;
       }
       //if we don't find a match, go to next element
       else
           return two_the_same(cdr(p), q);
   }
   return two_the_same(car(p), q) || two_the_same(cdr(p), q);

}

bool equal(list p, list q)
{

    //if 'p' or 'q' ever reaches null that means one of our lists are different from the other
    if(is_null(p) || is_null(q))
    {
        return is_null(p) && is_null(q);

    }
    //next two cases check if one or the other is an atom or not
    if(is_atom(car(p)) && !is_atom(car(q)))
    {
        return false;
    }
    if(!is_atom(car(p)) && is_atom(car(q)))
    {
        return false;
    }

    //if we hit an atom, check if equal
    if(is_atom(car(p)) && is_atom(car(q)))
    {
        //if our atoms are equal, go to next element
        if(eq(car(p), car(q)))
        {
            return equal(cdr(p), cdr(q));
        }
        else
            return false;
    }
    //go further into list if they are both not atoms
    return equal(car(p), car(q));


}

//paranthisis in wrong spots
list total_reverse(list p)
{
    if(is_null(p))
    {
        return null();
    }
    //if we have an atom in car(p), traverse to the end of the list and put last element in list first
    if(is_atom(car(p)))
    {
        return append(total_reverse(cdr(p)), cons(car(p), null()));
    }

    //if we don't find an atom, go deeper into the nested list
    return append(total_reverse(cdr(p)), cons(total_reverse(car(p)), null()));
}


list shape(list p)
{
    if(is_null(p))
    {
        return null();
    }
    //if we have a list of atoms, we are going to make it to base case and return
    //a null list (paranthisis).
    if(is_atom(car(p)))
    {
        return shape(cdr(p));
    }

    //If we don't run into an atom, recursively traverse down the list into our nested lists
    return append(cons(shape(car(p)), null()), shape(cdr(p)));
}

list intersection(list p, list q)
{
    //if p is ever null, return the list
    if(is_null(p))
    {
        return p;
    }

    //if we find an atom 'p' in q, use member to find if it's a member of 'q'.
    //if we do find it, add it to a list and recursively call to go deeper into 'p'
    if(member(car(p), q))
    {
        return append(cons(car(p), null()), intersection(cdr(p), q));

    }
    //if we don't find a member of atom 'p' in 'q', go deeper into 'p' and search with the next element
    return intersection(cdr(p), q);
}

list list_union(list p, list q)
{
    //if 'q' is null return the finished list
    if(is_null(q))
    {
        return append(p, null());
    }
    //if 'p' is null, return finished list
    if(is_null(p))
    {
        return append(q, null());
    }

    //if our atom from 'p' is not in 'q', attach our atom to our list, then recursively
    //call list_union with the next element in 'p' and q.
    if(!member(car(p), q))
    {
        return cons(car(p), list_union(cdr(p), q));
    }
    //if the atom appears once in both lists, call union with next element of 'p'
    return append(list_union(cdr(p), q), null());


}
//count atoms at top level of list p
int numAtomsAtTheTopLevel(list p)
{
    if(is_null(p))
    {
        return 0;
    }

    if(is_atom(car(p)))
    {
        return 1 + numAtomsAtTheTopLevel(cdr(p));
    }
    numAtomsAtTheTopLevel(cdr(p));
}


//Find shallow member atom
bool smember(list p, list q)
{
    //check for empty list first
    if(is_null(p))
    {
        return false;
    }

    if(eq(car(p), q))
    {
        return true;
    }

    return smember(cdr(p), q);
}


//p is a list of atoms
//q is a list of atoms
//p & q have the same number of atoms
// the function returns true if the atoms in p are the same as those in q
// and in the same order
// EX: (a b c d) (a b c d). returns true
bool areEqual(list p, list q)
{
    if(is_null(p))
    {
        return true;
    }

    if(eq(car(p), car(q)))
    {
        return areEqual(cdr(p), cdr(q));
    }
    return false;
}

list repeatAtom(list p, int n)
{
    if(n == 0)
    {
        return null();
    }

    // n is 5 ~~ (a a a a)
    //cons(p, repeatAtom(p, n-1))
    return cons(p, repeatAtom(p, n-1));

}

//append examples
//(a) () -> (a)
//() (a) -> (a)
// ((a) b) (a (b)) -> ((a) b a (b))

list append(list p, list q)
{
    if(is_null(p)){
        return q;
    }

    return cons(car(p), append(cdr(p), q));
}

//shallow reverse
list sreverse(list p)
{
    if(is_null(p))
    {
        return null();
    }

        return append(sreverse((cdr(p))), cons(car(p), null()));

}