// Filename        : PerlList.h
// Created         : 04/17/1999
// Author          : Matt Youell
// Description     : A Perl-inspired list.
// Last Updated    : 04/25/1999
// Version         : 0.110
// QC Status       : Untested
// ------------------------------------------------------------------

/*

PerlString v0.900

DISCLAIMER

This software is not guaranteed in any way, by any person or entity.

LICENSING

This software is copyright (c) 1999, 2000 Matt Youell.

Use of this software is governed by the Artistic License, which is 
available at  http://www.perl.com/language/misc/Artistic.html.

For your convenience, a copy of the Artistic License is included at 
the bottom of this file.

This licensing arrangement is subject to change.

BUGS, SUGGESTIONS, ETC.

Please send all correspondence regarding PerlString to 
DISCLAIMER

This software is not guaranteed in any way, by any person or entity.
matt@youell.com.

UPDATES

Visit http://www.youell.com/matt/perlstring/ to download the latest
release of PerlString.

*/



#ifndef PERL_LIST_H
#define PERL_LIST_H

#include <deque>
using namespace std;

template<class Item>
class PerlList
{
    protected:

    deque<Item> List;

    Item TempItem;

    public:

    PerlList();

    PerlList(const PerlList<Item>&givenList);

    long push(Item& givenItem);

    long push(PerlList& givenList);

    long unshift(Item& givenItem);

    long unshift(PerlList& givenList);

    Item& operator[] (long givenIndex);

    void operator = (const PerlList& givenList);

    Item& pop();

    Item& shift();

    bool shift(Item& givenItem);

    long scalar();

    bool defined();

    void undef();

    void splice(long offset, long length, PerlList<Item>& givenList);

    void reverse();

//    void sort();
};



template<class Item>
long PerlList<Item>::push(Item& givenItem)
{
    List.push_back(givenItem);
    return List.size();
}

template<class Item>
long PerlList<Item>::push(PerlList& givenList)
{
    for(long i = 0; i < givenList.scalar(); i++)
    {
        List.push_back(&givenList[i]);
    }

    return List.size();
}

template<class Item>
long PerlList<Item>::unshift(Item& givenItem)
{
    List.push_front(&givenItem);

    return List.size();
}

template<class Item>
long PerlList<Item>::unshift(PerlList& givenList)
{
    for(long i = (givenList.scalar() - 1); i >= 0 ; i--)
    {
        List.push_front(&givenList[i]);
    }

    return List.size();
}


template<class Item>
bool PerlList<Item>::pop()
{
    if(List.empty())
    {
        // Can't shift off of an empty list!
        return false;
    }

    givenItem = List.back();

    List.pop_back();

    return true;
}


template<class Item>
bool PerlList<Item>::shift(Item& givenItem)
{
    if(List.empty())
    {
        // Can't shift off of an empty list!
        return false;
    }

    givenItem = List.front();

    List.pop_front();

    return true;
}


template<class Item>
Item& PerlList<Item>::operator[] (long givenIndex)
{
    // We need to write some wrap-around code here so that
    // negative indexes and huge indexes end of doing semi-sane
    // things.
    return List[givenIndex];
}



template<class Item>
bool PerlList<Item>::defined()
{
    bool def = List.empty();
    return !def;
}

template<class Item>
void PerlList<Item>::undef()
{
    List.clear();
    return;
}

template<class Item>
long PerlList<Item>::scalar()
{
    return List.size();
}


template<class Item>
void PerlList<Item>::splice(long offset, long length, PerlList<Item>& givenList)
{
    for(long i = 0; ( (i < length) && (!givenList.empty()) ); i++)
    {
        List.insert( (List.begin() + offset + i), givenList[i]);
    }

    return;
}


template<class Item>
void PerlList<Item>::reverse()
{
    // (Not the speediest method, to be sure.)


    // Build a new list.

    deque<Item> tempList;


    // Then fill it up in reverse.

    for(unsigned long i = 0; i < List.size(); i++)
    {
        tempList.push_front(List[i]);
    }


    // Finally, swap contents. Voila!

    tempList.swap(List);

    return;
}



template<class Item>
PerlList<Item>::PerlList()
{
    // Nothing to put here yet, but we needed an empty constructor.
}


template<class Item>
PerlList<Item>::PerlList(const PerlList& givenList)
{
    List.assign( givenList.List.begin(), givenList.List.end() );
}

template<class Item>
void PerlList<Item>::operator = (const PerlList& givenList)
{
    List.assign( givenList.List.begin(), givenList.List.end() );
}

/*
template<class Item>
void sort()
{

}
*/

#endif




/*

The following is a copy of the Artisitc License, under which this software is released.
The Artistic License is also available at http://www.perl.com/language/misc/Artistic.html.


The "Artistic License"


Preamble

The intent of this document is to state the conditions under which a Package 
may be copied, such that the Copyright Holder maintains some semblance of 
artistic control over the development of the package, while giving the users of 
the package the right to use and distribute the Package in a more-or-less 
customary fashion, plus the right to make reasonable modifications.

Definitions

"Package" refers to the collection of files distributed by the Copyright 
Holder, and derivatives of that collection of files created through textual 
modification.

"Standard Version" refers to such a Package if it has not been modified, or 
has been modified in accordance with the wishes of the Copyright Holder as 
specified below.

"Copyright Holder" is whoever is named in the copyright or copyrights for 
the package.

"You" is you, if you're thinking about copying or distributing this 
Package.

"Reasonable copying fee" is whatever you can justify on the basis of media 
cost, duplication charges, time of people involved, and so on. (You will not 
be required to justify it to the Copyright Holder, but only to the computing 
community at large as a market that must bear the fee.)

"Freely Available" means that no fee is charged for the item itself, though 
there may be fees involved in handling the item. It also means that recipients 
of the item may redistribute it under the same conditions they received it. 


1. You may make and give away verbatim copies of the source form of the 
Standard Version of this Package without restriction, provided that you 
duplicate all of the original copyright notices and associated disclaimers. 

2. You may apply bug fixes, portability fixes and other modifications derived 
from the Public Domain or from the Copyright Holder. A Package modified in 
such a way shall still be considered the Standard Version. 

3. You may otherwise modify your copy of this Package in any way, provided 
that you insert a prominent notice in each changed file stating how and when 
you changed that file, and provided that you do at least ONE of the following: 

	a. place your modifications in the Public Domain or otherwise make them 
	Freely Available, such as by posting said modifications to Usenet or an 
	equivalent medium, or placing the modifications on a major archive site such 
	as uunet.uu.net, or by allowing the Copyright Holder to include your 
	modifications in the Standard Version of the Package. 

	b. use the modified Package only within your corporation or organization. 

	c. rename any non-standard executables so the names do not conflict with 
	standard executables, which must also be provided, and provide a separate 
	manual page for each non-standard executable that clearly documents how it 
	differs from the Standard Version. 

	d. make other distribution arrangements with the Copyright Holder.

4. You may distribute the programs of this Package in object code or 
executable form, provided that you do at least ONE of the following: 

	a. distribute a Standard Version of the executables and library files, 
	together with instructions (in the manual page or equivalent) on where to 
	get the Standard Version. 

	b. accompany the distribution with the machine-readable source of the 
	Package with your modifications. 

	c. give non-standard executables non-standard names, and clearly document 
	the differences in manual pages (or equivalent), together with instructions 
	on where to get the Standard Version. 

	d. make other distribution arrangements with the Copyright Holder.

5. You may charge a reasonable copying fee for any distribution of this 
Package. You may charge any fee you choose for support of this Package. You 
may not charge a fee for this Package itself. However, you may distribute this 
Package in aggregate with other (possibly commercial) programs as part of a 
larger (possibly commercial) software distribution provided that you do not 
advertise this Package as a product of your own. You may embed this Package's 
interpreter within an executable of yours (by linking); this shall be 
construed as a mere form of aggregation, provided that the complete Standard 
Version of the interpreter is so embedded. 

6. The scripts and library files supplied as input to or produced as output 
from the programs of this Package do not automatically fall under the 
copyright of this Package, but belong to whomever generated them, and may be 
sold commercially, and may be aggregated with this Package. If such scripts or 
library files are aggregated with this Package via the so-called "undump" or 
"unexec" methods of producing a binary executable image, then distribution of 
such an image shall neither be construed as a distribution of this Package nor 
shall it fall under the restrictions of Paragraphs 3 and 4, provided that you 
do not represent such an executable image as a Standard Version of this 
Package. 

7. C subroutines (or comparably compiled subroutines in other languages) 
supplied by you and linked into this Package in order to emulate subroutines 
and variables of the language defined by this Package shall not be considered 
part of this Package, but are the equivalent of input as in Paragraph 6, 
provided these subroutines do not change the language in any way that would 
cause it to fail the regression tests for the language. 

8. Aggregation of this Package with a commercial distribution is always 
permitted provided that the use of this Package is embedded; that is, when no 
overt attempt is made to make this Package's interfaces visible to the end 
user of the commercial distribution. Such use shall not be construed as a 
distribution of this Package. 

9. The name of the Copyright Holder may not be used to endorse or promote 
products derived from this software without specific prior written permission. 

10.THIS PACKAGE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR IMPLIED 
WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF 
MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE. 

The End

*/
