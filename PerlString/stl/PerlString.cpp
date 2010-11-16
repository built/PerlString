// Filename        : PerlString.cpp
// Created         : 09/08/1999
// Author          : Matt Youell
// Description     : An STL implementation of a Perl inspired string class for C++.
// Last Updated    : 09/08/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
#include <condefs.h>
#include <iostream.h>
#include <string.h>
#include <math.h>
#include "PerlString.h"
#pragma hdrstop
#define Library

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::PerlString()
// Created         : 03/14/1999
// Author          : Matt Youell
// Description     : Constructor with no parameters.
// Last Updated    : 03/14/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
PerlString::PerlString()
{
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------


// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::PerlString(char*)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Constructor, taking a C-style string.
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
PerlString::PerlString(char* givenString)
{
    Text.assign(givenString);
}

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::PerlString(char*)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Constructor, taking a C-style string.
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
PerlString::PerlString(const char* givenString)
{
    Text.assign(givenString);
}


// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------



// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::PerlString(PerlString*)
// Created         : 03/14/1999
// Author          : Matt Youell
// Description     : Constructor, taking a PerlString.
// Last Updated    : 03/14/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
PerlString::PerlString(PerlString* givenString)
{
    if(givenString != NULL)
    {
        Text.assign(givenString->getText());
    }
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------


// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::PerlString(const PerlString&)
// Created         : 04/18/1999
// Author          : Matt Youell
// Description     : Copy constructor.
// Last Updated    : 04/18/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
PerlString::PerlString(const PerlString& givenString)
{
        Text = givenString.Text;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------


// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::~PerlString()
// Created         : 03/14/1999
// Author          : Matt Youell
// Description     : Destructor.
// Last Updated    : 03/14/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
PerlString::~PerlString()
{

}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------


// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::setText()
// Created         : 03/14/1999
// Author          : Matt Youell
// Description     : Copy the given string into our buffer.
// Last Updated    : 03/14/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::setText(char* givenString)
{
    bool set = false;

    if(givenString != NULL)
    {
        Text.assign(givenString);
        set = true;
    }

    return set;
}

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::getText()
// Created         : 03/14/1999
// Author          : Matt Youell
// Description     : Return a pointer to our string buffer.
// Last Updated    : 03/14/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
const char* PerlString::getText()
{
    return Text.c_str();
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------


// ------------------------------------------------------------------
// CHAR* COMPARATORS
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::lt(char*)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Less than?
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::lt(char* givenString)
{
    bool lessThan = (Text < givenString);

    return lessThan;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::gt(char*)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Greater than?
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::gt(char* givenString)
{
    bool greaterThan = (Text > givenString);

    return greaterThan;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::eq(char*)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Equal?
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::eq(char* givenString)
{
    bool equalTo = (Text == givenString);

    return equalTo;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::ne(char*)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Not equal?
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::ne(char* givenString)
{
    bool notEqualTo = false;

    notEqualTo = (Text != givenString);

    return notEqualTo;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::le(char*)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Less than or equal?
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::le(char* givenString)
{
    bool lessThanOrEqualTo = false;
    lessThanOrEqualTo = (Text <= givenString);
    
    return lessThanOrEqualTo;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::ge(char*)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Greater than or equal?
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::ge(char* givenString)
{
    bool greaterThanOrEqualTo = false;
    greaterThanOrEqualTo = (Text >= givenString);
    
    return greaterThanOrEqualTo;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::cmp(char*)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Compares two strings.
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
int PerlString::cmp(char* givenString)
{
    int result = Text.compare(givenString);

    return result;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------



// ------------------------------------------------------------------
// PERLSTRING POINTER COMPARATORS
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::lt(PerlString*)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Less than?
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::lt(PerlString* givenString)
{
    bool lessThan = false;

    if(givenString != NULL)
    {
        lessThan = (Text < givenString->getText());
    }

    return lessThan;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::gt(PerlString*)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Greater than?
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::gt(PerlString* givenString)
{
    bool greaterThan = false;

    if(givenString != NULL)
    {
        greaterThan = (Text > givenString->getText());
    }

    return greaterThan;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::eq(PerlString*)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Equal?
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::eq(PerlString* givenString)
{
    bool equalTo = false;

    if(givenString != NULL)
    {
        equalTo = (Text == givenString->getText());
    }

    return equalTo;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::ne(PerlString*)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Not equal?
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::ne(PerlString* givenString)
{
    bool notEqualTo = false;

    if(givenString != NULL)
    {
        notEqualTo = (Text != givenString->getText());
    }

    return notEqualTo;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::le(PerlString*)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Less than or equal?
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::le(PerlString* givenString)
{
    bool lessThanOrEqualTo = false;

    if(givenString != NULL)
    {
        lessThanOrEqualTo = (Text <= givenString->getText());
    }

    return lessThanOrEqualTo;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::ge(PerlString*)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Greater than or equal?
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::ge(PerlString* givenString)
{
    bool greaterThanOrEqualTo = false;

    if(givenString != NULL)
    {
        greaterThanOrEqualTo = (Text >= givenString->getText());
    }

    return greaterThanOrEqualTo;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::cmp(PerlString*)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Compares two strings.
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
int PerlString::cmp(PerlString* givenString)
{
    int result = -1;

    if(givenString != NULL)
    {
        result = Text.compare(givenString->getText());
    }

    return result;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------



// ------------------------------------------------------------------
// PERLSTRING REFERENCE COMPARATORS
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::lt(PerlString&)
// Created         : 04/18/1999
// Author          : Matt Youell
// Description     : Less than?
// Last Updated    : 04/18/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::lt(PerlString& givenString)
{
    bool lessThan = (Text < givenString.getText());

    return lessThan;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::gt(PerlString&)
// Created         : 04/18/1999
// Author          : Matt Youell
// Description     : Greater than?
// Last Updated    : 04/18/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::gt(PerlString& givenString)
{
    bool greaterThan = (Text > givenString.getText());

    return greaterThan;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::eq(PerlString&)
// Created         : 04/18/1999
// Author          : Matt Youell
// Description     : Equal?
// Last Updated    : 04/18/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::eq(PerlString& givenString)
{
    bool equalTo = (Text == givenString.getText());

    return equalTo;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::ne(PerlString&)
// Created         : 04/18/1999
// Author          : Matt Youell
// Description     : Not equal?
// Last Updated    : 04/18/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::ne(PerlString& givenString)
{
    bool notEqualTo = (Text != givenString.getText());

    return notEqualTo;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::le(PerlString&)
// Created         : 04/18/1999
// Author          : Matt Youell
// Description     : Less than or equal?
// Last Updated    : 04/18/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::le(PerlString& givenString)
{
    bool lessThanOrEqualTo = (Text <= givenString.getText());

    return lessThanOrEqualTo;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::ge(PerlString&)
// Created         : 04/18/1999
// Author          : Matt Youell
// Description     : Greater than or equal?
// Last Updated    : 04/18/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::ge(PerlString& givenString)
{
    bool greaterThanOrEqualTo = (Text >= givenString.getText());

    return greaterThanOrEqualTo;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::cmp(PerlString&)
// Created         : 04/18/1999
// Author          : Matt Youell
// Description     : Compares two strings.
// Last Updated    : 04/18/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
int PerlString::cmp(PerlString& givenString)
{
    int result = Text.compare(givenString.getText());

    return result;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------


// ------------------------------------------------------------------
// CHAR* COMPARATORS
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::operator < (char*)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Less than?
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::operator <  (char *givenString)
{
    bool lessThan = (Text < givenString);

    return lessThan;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::operator > (char*)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Greater than?
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::operator >  (char *givenString)
{
    bool greaterThan = (Text > givenString);

    return greaterThan;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::operator == (char*)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Equal?
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::operator == (char *givenString)
{
    bool equalTo = (Text == givenString);

    return equalTo;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::operator != (char*)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Not equal?
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::operator != (char *givenString)
{
    bool notEqualTo = (Text != givenString);

    return notEqualTo;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::operator <= (char*)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Less than or equal?
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::operator <= (char *givenString)
{
    bool lessThanOrEqualTo = false;
    lessThanOrEqualTo = (Text <= givenString);
    
    return lessThanOrEqualTo;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::operator >= (char*)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Greater than or equal?
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::operator >= (char *givenString)
{
    bool greaterThanOrEqualTo = false;
    greaterThanOrEqualTo = (Text >= givenString);
    
    return greaterThanOrEqualTo;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
// PERLSTRING POINTER COMPARATORS
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::operator < (PerlString*)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Less than?
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::operator <  (PerlString* givenString)
{
    bool lessThan = false;

    if(givenString != NULL)
    {
        lessThan = (Text < givenString->getText());
    }

    return lessThan;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::operator > (PerlString*)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Greater than?
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::operator >  (PerlString* givenString)
{
    bool greaterThan = false;

    if(givenString != NULL)
    {
        greaterThan = (Text < givenString->getText());
    }

    return greaterThan;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::operator == (PerlString*)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Equal?
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::operator == (PerlString* givenString)
{
    bool equalTo = false;

    if(givenString != NULL)
    {
        equalTo = (Text == givenString->getText());
    }

    return equalTo;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::operator != (PerlString*)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Not equal?
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::operator != (PerlString* givenString)
{
    bool notEqualTo = false;

    if(givenString != NULL)
    {
        notEqualTo = (Text == givenString->getText());
    }

    return notEqualTo;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::operator <= (PerlString*)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Less than or equal?
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::operator <= (PerlString* givenString)
{
    bool lessThanOrEqualTo = false;

    if(givenString != NULL)
    {
        lessThanOrEqualTo = (Text <= givenString->getText());
    }

    return lessThanOrEqualTo;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::operator >= (PerlString*)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Greater than or equal?
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::operator >= (PerlString* givenString)
{
    bool greaterThanOrEqualTo = false;

    if(givenString != NULL)
    {
        greaterThanOrEqualTo = (Text >= givenString->getText());
    }

    return greaterThanOrEqualTo;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------


// ------------------------------------------------------------------
// PERLSTRING REFERENCE COMPARATORS
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::operator < (PerlString&)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Less than?
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::operator <  (PerlString& givenString)
{
    bool lessThan = (Text < givenString.getText());

    return lessThan;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::operator > (PerlString&)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Greater than?
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::operator >  (PerlString& givenString)
{
    bool greaterThan = (Text > givenString.getText());

    return greaterThan;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::operator == (PerlString&)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Equal?
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::operator == (PerlString& givenString)
{
    bool equalTo = (Text == givenString.getText());

    return equalTo;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::operator != (PerlString&)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Not equal?
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::operator != (PerlString& givenString)
{
    bool notEqualTo = (Text != givenString.getText());

    return notEqualTo;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::operator <= (PerlString&)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Less than or equal?
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::operator <= (PerlString& givenString)
{
    bool lessThanOrEqualTo = (Text <= givenString.getText());

    return lessThanOrEqualTo;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::operator >= (PerlString&)
// Created         : 03/24/1999
// Author          : Matt Youell
// Description     : Greater than or equal?
// Last Updated    : 03/24/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::operator >= (PerlString& givenString)
{
    bool greaterThanOrEqualTo = (Text >= givenString.getText());

    return greaterThanOrEqualTo;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------





// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::chomp()
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     : Removes the end-of-line character(s). 
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
int PerlString::chomp()
{
    int chomped = 0;
    
    for(int i = Text.length() - 1; i >= 0; i--)
    {
        if( (Text[i] == '\n') || (Text[i] == '\r') )
        {
            chop();
        }
        else
        {
            // As soon as we hit a non-EOL char, stop.
            chomped = i;
            i = 0;
        }
    }

    return chomped;    
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------


// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::chop()
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     : Remove the last char in a string and return it.
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
char PerlString::chop()
{
    char c = Text[Text.size() - 1];

    Text.erase(Text.end() - 1, Text.end());

    return c;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------


// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::defined()
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     :
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::defined()
{
    bool notEmpty = (Text.size() > 0);

    return notEmpty;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------


// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::hex()
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     : Treat string as hex, and return the dec value.
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
int PerlString::hex()
{
    long value = 0L;

    sscanf(Text.c_str(),"%x", &value);

    return value;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------


// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::index(char*)
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     : Returns the pos of the first or next occ of str.
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
long PerlString::index(char* givenString)
{
    return Text.find(givenString);
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::integer()
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     : Returns the integer value of the string.
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
int PerlString::integer()
{
    int value = atoi(Text.c_str());
    
    return value;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------


// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::lc()
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     : Convert all chars in string to lower case.
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
PerlString PerlString::lc()
{
    string temp(Text);

    for(unsigned int i = 0; i < temp.length(); i++)
    {
        temp[i] = (char) tolower(temp[i]);
    }

    PerlString str(temp.c_str());

    return str;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------


// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::lcfirst()
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     :
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
PerlString PerlString::lcfirst()
{
    string temp(Text);

    temp[0] = (char) tolower(temp[0]);

    PerlString str(temp.c_str());

    return str;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------


// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::length()
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     : Return the length of the string.
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
long PerlString::length()
{
    return Text.length();
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------


// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::oct()
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     : Treat string as oct, and return the dec value.
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
int PerlString::oct()
{
    int value = 0L;

    sscanf(Text.c_str(),"%o", &value);

    return value;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------


// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::ord()
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     : Returns the ASCII value of the first char.
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
unsigned char PerlString::ord()
{
    unsigned char c = Text[0];

    return c;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::reset()
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     :
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
void PerlString::reset()
{
    // "Vaguely deprecated."
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------


// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::reverse()
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     :
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
PerlString PerlString::reverse()
{
    string temp(Text);
    
    std::reverse(temp.begin(), temp.end());

    PerlString str(temp.c_str());

    return str;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::rindex(char*)
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     : Find the index of the last occurence of substr.
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
long PerlString::rindex(char* givenString)
{
    return Text.rfind(givenString);
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::substr(long, long)
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     : Copies data out of the string into a new one.
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
PerlString PerlString::substr(long offset, long len)
{
    string str;

    str.assign(Text.begin()+ offset, Text.begin()+ offset + len);

    PerlString perlStr(str.c_str());

    return perlStr;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::tr(char, char)
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     : Translates all instances of a char into another.
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
int PerlString::tr(char givenOldCharacter, char givenNewCharacter)
{
    int totalChars = 0;

    for(unsigned int i = 0; i < Text.length(); i++)
    {
        if(Text[i] == givenOldCharacter)
        {
            Text[i] = givenNewCharacter;
            totalChars++;
        }
    }

    return totalChars;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::uc()
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     : Convert all chars in string to upper case.
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
PerlString PerlString::uc()
{
    string temp(Text);

    for(unsigned int i = 0; i < temp.length(); i++)
    {
        temp[i] = (char) toupper(temp[i]);
    }

    PerlString str(temp.c_str());

    return str;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::ucfirst()
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     : Makes the first char in the string uppercase.
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
PerlString PerlString::ucfirst()
{
    string temp(Text);

    temp[0] = (char) toupper(temp[0]);

    PerlString str(temp.c_str());

    return str;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::undef()
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     : Sets the string to be undefined.
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
char* PerlString::undef()
{
    Text.empty();

    return NULL;    
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------



// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::split
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     :
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
long PerlString::split(PerlStringList& givenList, char* givenPattern)
{
    // Hold off until regex support is added.
    return 0;
}

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------




// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     :
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
// void PerlString::crypt();        // TO DO
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     :
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
// char* PerlString::unpack();      // TO DO
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------


// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::operator [] (long)
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     : Returns the value of the character at the index.
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
char PerlString::operator [] (long  givenIndex)
{
    // We use a wrap-around approach to indexing.
    // In other words, if the given index on a 10 char string is -2,
    // the "real" index that will be used is 8.

    // Find the "real" index value of the index passed in.

    long realIndex = 0;

    long len = Text.length();

    if( (givenIndex >= 0) && (givenIndex < len) )
    {
        // This index is OK to use as-is.
        realIndex = givenIndex;
    }
    else
    if(givenIndex < 0)
    {
        realIndex = (len + givenIndex);
        realIndex = (realIndex % len);
    }
    else
    if(givenIndex >= len)
    {
        realIndex = (givenIndex - len);
        realIndex = (realIndex % len);
    }

    return Text[realIndex];
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::operator +  (char* givenString)
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     : Concatenate two strings and return them as one.
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
PerlString PerlString::operator +  (char* givenString)
{
    PerlString result = Text.c_str();

    if(givenString != NULL)
    {
        result += givenString;
    }

    return result;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::operator +  (PerlString* givenString)
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     : Concatenate two strings and return them as one.
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
PerlString PerlString::operator +  (PerlString* givenString)
{
    PerlString result = Text.c_str();

    if(givenString != NULL)
    {
        result += givenString->getText();
    }

    return result;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------


// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::operator + (PerlString& givenString)
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     : Concatenate two strings and return them as one.
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
PerlString	PerlString::operator +  (PerlString& givenString)
{
    PerlString result = Text.c_str();

    result += givenString.getText();

    return result;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------


// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::operator = (char*)
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     : Sets the string with the given content.
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
void PerlString::operator = (char* givenString)
{
    if(givenString != NULL)
    {
        Text = givenString;
    }

    return;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::operator = (PerlString*)
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     : Sets the string with the given content.
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
void PerlString::operator = (PerlString* givenString)
{
    if(givenString != NULL)
    {
        Text = givenString->getText();
    }

    return;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::operator = (PerlString&)
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     : Sets the string with the given content.
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
void PerlString::operator = (PerlString& givenString)
{
    Text = givenString.getText();

    return;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------


// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::operator *= (unsigned int)
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     : Appends this string onto itself n times.
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
void PerlString::operator *= (unsigned int givenMultiplier)
{
    for(unsigned int i = 0; i < givenMultiplier; i++)
    {
        Text.append(Text.begin(), Text.end());
    }

    return;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::operator += (char)
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     : Appends a character onto the end of this string.
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
void PerlString::operator += (char givenCharacter)
{
    Text += givenCharacter;

    return;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------



// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::operator += (char*)
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     : Appends a string onto the end of this one.
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
void PerlString::operator += (char* givenString)
{
    if(givenString != NULL)
    {
        Text += givenString;
    }

    return;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::operator += (const char*)
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     : Appends a string onto the end of this one.
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
void PerlString::operator += (const char* givenString)
{
    if(givenString != NULL)
    {
        Text += givenString;
    }

    return;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------



// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::operator += (PerlString*)
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     : Appends a string onto the end of this one.
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
void PerlString::operator += (PerlString* givenString)
{
    if(givenString != NULL)
    {
        Text += givenString->getText();
    }

    return;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::operator += (PerlString&)
// Created         : 03/25/1999
// Author          : Matt Youell
// Description     : Appends a string onto the end of this one.
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
void PerlString::operator += (PerlString& givenString)
{
    Text += givenString.getText();

    return;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------


