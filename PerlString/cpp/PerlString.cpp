// Filename        : PerlString.cpp
// Created         : 03/14/1999
// Author          : Matt Youell
// Description     : A Perl inspired string class for C++.
// Last Updated    : 03/14/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
#include <condefs.h>
#include <iostream.h>
#include <string.h>
#include <math.h>
#include "PerlString.h"

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
    BlockSize    = 16;       // This can be fine tuned for perfomance.
    StringSize   = 0;
    TempBuffer   = 0;
    Buffer       = new char[BlockSize];
    Buffer[0]    = 0;
    BufferSize   = BlockSize;
    CurrentIndex = 0;

    BytesAllocated = BlockSize;
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
    BlockSize   = 16;       // This can be fine tuned for perfomance.
    StringSize  = 0;
    TempBuffer  = 0;
    Buffer      = new char[BlockSize];
    Buffer[0]   = 0;
    BufferSize  = BlockSize;

    setText(givenString);

    BytesAllocated = BlockSize;
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
    BlockSize   = 16;       // This can be fine tuned for perfomance.
    StringSize  = 0;
    TempBuffer  = 0;
    Buffer      = new char[BlockSize];
    Buffer[0]   = 0;
    BufferSize  = BlockSize;

    if(givenString != NULL)
    {
        setText(givenString->getText());
    }

    BytesAllocated = BlockSize;
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
    BlockSize   = givenString.BlockSize;
    StringSize  = givenString.StringSize;
    TempBuffer  = givenString.TempBuffer;
    Buffer      = new char[givenString.BufferSize];
    Buffer[0]   = 0;
    BufferSize  = BlockSize;
    setText(givenString.getText());
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
    // Clean up.
    delete[] Buffer;
    delete[] TempBuffer;

    // And better safe than sorry...
    Buffer = 0;
    TempBuffer = 0;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------



// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::Resize()
// Created         : 03/14/1999
// Author          : Matt Youell
// Description     : Resize to accomodate a string of the given size.
// Last Updated    : 03/14/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::Resize(long givenSize)
{
    bool result = true;

    givenSize++;    // Adjust to allow for a null terminator.

    if(givenSize > BufferSize)
    {
        result = Expand(givenSize);
    }
    else if(givenSize < BufferSize)
    {
        result = Contract(givenSize);
    }

    // If no resize was necessary, 'result' will always be true.

    return result;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------



// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::Expand()
// Created         : 03/14/1999
// Author          : Matt Youell
// Description     : Expand buffer to the given size
// Last Updated    : 03/14/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::Expand(long givenSize)
{
    bool result = false;    // Assume failure by default.

    long blocksNeeded  = ((givenSize / BlockSize) + 1);

    long newBufferSize = (blocksNeeded * BlockSize);

    delete[] TempBuffer;

    TempBuffer = 0;

    TempBuffer = new char[newBufferSize];

BytesAllocated += newBufferSize;

    if(TempBuffer == NULL)
    {
        result = false;
    }
    else
    {
        // Copy the existing buffer into the new buffer.
        strncpy(TempBuffer, Buffer, BufferSize);

        // Fill the extra space with nulls.
        memset(&TempBuffer[BufferSize], 0, (newBufferSize - BufferSize));

        // Release the old buffer space back to the system.
        delete[] Buffer;

        Buffer = 0;

BytesAllocated -= BufferSize;

        // Update names and pointers.
        Buffer     = TempBuffer;
        TempBuffer = 0;

        // Update our memory statistics.
        BufferSize = newBufferSize;

        // Note our success.
        result = true;
    }

    return result;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - BEGIN
// ------------------------------------------------------------------
// Component Name  : PerlString::Contract()
// Created         : 03/14/1999
// Author          : Matt Youell
// Description     : Contract buffer to it's minimum size.
// Last Updated    : 03/14/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::Contract(long givenSize)
{
    bool result = false;    // Assume failure by default.

    long blocksNeeded  = ((givenSize / BlockSize) + 1);

    long newBufferSize = (blocksNeeded * BlockSize);

    delete[] TempBuffer;

    TempBuffer = 0;

    TempBuffer = new char[newBufferSize];

BytesAllocated += newBufferSize;

    if(TempBuffer == NULL)
    {
        result = false;
    }
    else
    {
        // Copy what we can of the existing buffer into the new buffer.
        strncpy(TempBuffer, Buffer, newBufferSize);

        // Make sure there is a terminating null, just in case.
        TempBuffer[newBufferSize - 1] = 0;


        // Release the old buffer space back to the system.
        delete[] Buffer;

        Buffer = 0;

BytesAllocated -= BufferSize;

        // Update names and pointers.
        Buffer     = TempBuffer;
        TempBuffer = 0;

        // Update our memory statistics.
        BufferSize = newBufferSize;

        // Note our success.
        result = true;
    }

    return result;
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
    // Validate given string.
    // Valid values go from zero (null string) on up.

    long length = strlen(givenString);

    if(length < 0)
    {
        return false;
    }

    // Resize the buffer to accomodate the given string.
    if(Resize(length) == false)
    {
        return false;
    }

    // Update the new string size.
    StringSize = length;


    // Copy the given string over our current string.
    strncpy(Buffer, givenString, StringSize);


    // Make sure that we're null terminated.
    Buffer[StringSize] = 0;

    return true;
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
char* PerlString::getText()
{
    return Buffer;
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
    return (strcmp(givenString, Buffer) < 0);
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
    return (strcmp(givenString, Buffer) > 0);
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
    return (strcmp(givenString, Buffer) == 0);
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
    return (strcmp(givenString, Buffer) != 0);
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
    return (strcmp(givenString, Buffer) <= 0);
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
    return (strcmp(givenString, Buffer) >= 0);
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
  return strcmp(givenString, Buffer);
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
    return (strcmp(givenString->getText(), Buffer) < 0);
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
    return (strcmp(givenString->getText(), Buffer) > 0);
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
    return (strcmp(givenString->getText(), Buffer) == 0);
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
    return (strcmp(givenString->getText(), Buffer) != 0);
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
    return (strcmp(givenString->getText(), Buffer) <= 0);
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
    return (strcmp(givenString->getText(), Buffer) >= 0);
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
  return strcmp(givenString->getText(), Buffer);
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
    return (strcmp(givenString.getText(), Buffer) < 0);
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
    return (strcmp(givenString.getText(), Buffer) > 0);
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
    return (strcmp(givenString.getText(), Buffer) == 0);
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
    return (strcmp(givenString.getText(), Buffer) != 0);
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
    return (strcmp(givenString.getText(), Buffer) <= 0);
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
    return (strcmp(givenString.getText(), Buffer) >= 0);
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
  return strcmp(givenString.getText(), Buffer);
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
    return lt(givenString);
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
    return gt(givenString);
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
    return eq(givenString);
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
    return ne(givenString);
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
    return le(givenString);
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
    return ge(givenString);
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
    return lt(givenString);
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
    return gt(givenString);
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
    return eq(givenString);
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
    return ne(givenString);
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
    return le(givenString);
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
    return ge(givenString);
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
    return lt(givenString);
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
    return gt(givenString);
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
    return eq(givenString);
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
    return ne(givenString);
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
    return le(givenString);
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
    return ge(givenString);
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
long PerlString::chomp()
{
    // We'll remove all occurences of CR or LF characters at the end
    // of the string. This will work on DOS, Unix, and Mac EOLs.

    // Start with the last character in the string and work back.
    long position = StringSize - 1;

    long chompedCharacters = 0;

    while( (Buffer[position] == '\r') || (Buffer[position] == '\n') )
    {
        // We've found either a CR or LF, so eliminate it.
        StringSize--;
        Buffer[position] = 0;
        position--;

        chompedCharacters++;
    }

    // Return the number of characters chomped.
    return chompedCharacters;
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
    long position     = StringSize - 1;

    char choppedChar  = Buffer[position];

    StringSize--;
    Buffer[position]  = 0;

    return choppedChar;
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
    // If the first char in the buffer is
    // a not null, then consider the contents
    // to be defined.

    return (Buffer[0] != 0);
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
long PerlString::hex()
{
    long decimalValue = 0;

    sscanf(Buffer, "%X", &decimalValue);

    return decimalValue;
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
    long  index  = -1;  // Default to indicating failure.
    char* position =  0;

    // We begin the search from the current index point.

    position = strstr(&Buffer[CurrentIndex], givenString);

    if(position != NULL)
    {
        // Because Buffer and givenString are just pointers (and
        // therefore just numbers), we can determine what the index
        // is like so:
        index = (long) (position - Buffer);
    }

    CurrentIndex = (index + 1); // The next search will start here.

    return index;
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
    return atoi(Buffer);
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
void PerlString::lc()
{
    strlwr(Buffer);

    return;
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
void PerlString::lcfirst()
{
    Buffer[0] = (char) tolower(Buffer[0]);

    return;
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
    return StringSize;
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
long PerlString::oct()
{
    long decimalValue = 0;

    sscanf(Buffer, "%O", &decimalValue);

    return decimalValue;
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
    return (unsigned char) Buffer[0];
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
    CurrentIndex = 0;

    return;
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
bool PerlString::reverse()
{
    strrev(Buffer);

    return true;
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
        long lastOffset = -1;   // In case don't find anything.
        long offset = 0;

        while(offset != -1)
        {
            lastOffset = offset;
            offset = index(givenString);
        }

        return lastOffset;
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
char* PerlString::substr(long offset, long len)
{
    TempBuffer = new char[len + 1];

    if(TempBuffer != 0)
    {
        strncpy(TempBuffer, &Buffer[offset], len);
        TempBuffer[len] = 0;
    }

    return TempBuffer;
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
long PerlString::tr(char givenOldCharacter, char givenNewCharacter)
{
    long count = 0;

    for(long i = 0; i < StringSize; i++)
    {
        if(Buffer[i] == givenOldCharacter)
        {
            Buffer[i] = givenNewCharacter;
            count++;
        }
    }

    return count;
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
void PerlString::uc()
{
    strupr(Buffer);
    return;
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
void PerlString::ucfirst()
{
    Buffer[0] = (char) toupper(Buffer[0]);

    return;
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
    // We set the first char in the Buffer
    // to null to make the string undefined.
    StringSize = 0;
    Buffer[0]  = 0;

    // Then we return the new string value. (Null)
    return Buffer;
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
long PerlString::split(PerlStringList& givenList, char givenCharacter)
{
    bool includeChar = false; // Including the split character has been deprecated.

    long stringStart    = 0;
    long stringLength   = 0;

    PerlString pString;

// cout << "Variables initialized." << endl;

    for(long i = 0; i <= StringSize; i++)
    {
// cout << "Inspecting position #" << i << ": "  << Buffer[i];

        if((Buffer[i] == givenCharacter) || (Buffer[i] == '\0'))
        {
// cout << " - MATCH";
            // We've found a dividing character.

            // Calculate how big a string we have.
            stringLength = (i - stringStart);

            // Only continue processing if we have a substring to copy.
            if(stringLength > 0)
            {
                // Now check to see if we're supposed to include the
                // givenCharacter in our extracted string.
                if(includeChar)
                {
                    stringLength++;
                }

// cout << " - (PerlString Created)";

                pString.setText(substr(stringStart, stringLength));

                givenList.push(pString);

                pString = "";

                stringStart  = (stringStart + stringLength);

                if(!includeChar)
                {
                    stringStart++; // Skip the given character for the next string.
                }

                stringLength = 0;
            }
            else
            {
                // If we arrived here, we probably have a dividing character
                // by itself, or we're at the end of the string, immediately
                // after a match.
                // If we're at the end of the string we should skip this
                // extra processing, otherwise, continue.
                if(Buffer[i] == givenCharacter)
                {
                    // Now we've determined that we do indeed have a
                    // dividing character by itself. So next we check
                    // to see if the character should be ignored, or
                    // have it's own string created.

                    // This character must have it's own string created.
                    if(includeChar)
                    {
// cout << " - (PerlString Created)";


                        pString.setText(substr(stringStart, 1));

                        givenList.push(pString);

                        pString = "";
                    }

                    // Either way, we'll skip this character so we can
                    // reach the next string.
                    stringStart++;
                }
            }
        }

//        cout << endl;
    }

    return givenList.scalar();
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
    char indexedCharacter = '\0';

    // We want it to be impossible go out of range.

    // First, if the given index is bigger than the
    // size of the string, we'll knock it down to size.

    if(labs(givenIndex) >= StringSize)
    {
        givenIndex = givenIndex % StringSize;
        // The givenIndex is now guaranteed to be in range,
        // whether negative or positive.
    }

    // Then if the given index is negative, treat it as a
    // reverse index into the string, rather than an invalid
    // value.
    if(givenIndex < 0)
    {
        // This looks weird, but remember that given index is
        // negative, and can never be zero, so it's more like
        // StringSize - abs(givenIndex).
        indexedCharacter = Buffer[(StringSize + givenIndex)];
    }
    else
    {
        indexedCharacter = Buffer[givenIndex];
    }

    return indexedCharacter;
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
char*	PerlString::operator +  (char* givenString)
{
    long givenStringLength = strlen(givenString);

    long combinedStringLength = givenStringLength + StringSize;

    delete[] TempBuffer;

    TempBuffer = 0;

    TempBuffer = new char[combinedStringLength + 1];

    if(TempBuffer != NULL)
    {
        strncpy(TempBuffer, Buffer, StringSize);
        strncpy(&TempBuffer[StringSize], givenString, givenStringLength);
        TempBuffer[combinedStringLength] = 0;
    }

    return TempBuffer;
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
char*	PerlString::operator +  (PerlString* givenString)
{
    long givenStringLength = givenString->length();

    long combinedStringLength = givenStringLength + StringSize;

    delete[] TempBuffer;

    TempBuffer = 0;

    TempBuffer = new char[combinedStringLength + 1];

    if(TempBuffer != NULL)
    {
        strncpy(TempBuffer, Buffer, StringSize);
        strncpy(&TempBuffer[StringSize], givenString->getText(), givenStringLength);
        TempBuffer[combinedStringLength] = 0;
    }

    return TempBuffer;
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
char*	PerlString::operator +  (PerlString& givenString)
{
    long givenStringLength = givenString.length();

    long combinedStringLength = givenStringLength + StringSize;

    delete[] TempBuffer;

    TempBuffer = 0;

    TempBuffer = new char[combinedStringLength + 1];

    if(TempBuffer != NULL)
    {
        strncpy(TempBuffer, Buffer, StringSize);
        strncpy(&TempBuffer[StringSize], givenString.getText(), givenStringLength);
        TempBuffer[combinedStringLength] = 0;
    }

    return TempBuffer;
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
bool PerlString::operator = (char* givenString)
{
    return setText(givenString);
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
bool PerlString::operator = (PerlString* givenString)
{
    return setText(givenString->getText());
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
bool PerlString::operator = (PerlString& givenString)
{
    return setText(givenString.getText());
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
bool PerlString::operator *= (unsigned int givenMultiplier)
{
    long newSize = (givenMultiplier * StringSize);

    bool result = false;

    char *myBuffer = 0;

    myBuffer = new char[newSize + 1];

    myBuffer[0] = 0; // Give concatenation a place to start.

    if(myBuffer != 0)
    {
        for(unsigned int i = 0; i < givenMultiplier; i++)
        {
            strcat(myBuffer, Buffer);
        }

        myBuffer[newSize] = 0;

        if(setText(myBuffer))
        {
            result = true;
        }
    }

    delete[] myBuffer;

    return result;
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
// Description     : Appends a string onto the end of this one.
// Last Updated    : 03/25/1999
// Version         : 0.100
// QC Status       : Untested
// ------------------------------------------------------------------
bool PerlString::operator += (char givenCharacter)
{
    long newSize = (StringSize + 1);

    bool result = false;

    char *myBuffer = 0;

    myBuffer = new char[newSize + 1];

    if(myBuffer != 0)
    {
        strcpy(myBuffer, Buffer);
        myBuffer[StringSize] = givenCharacter;
        myBuffer[newSize] = 0;

        if(setText(myBuffer))
        {
            result = true;
        }
    }

    delete[] myBuffer;

    return result;
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
bool PerlString::operator += (char* givenString)
{
    long newSize = (StringSize + strlen(givenString));

    bool result = false;

    char *myBuffer = 0;

    myBuffer = new char[newSize + 1];

    if(myBuffer != 0)
    {
        strcpy(myBuffer, Buffer);
        strcat(myBuffer, givenString);

        if(setText(myBuffer))
        {
            result = true;
        }
    }

    delete[] myBuffer;

    return result;
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
bool PerlString::operator += (PerlString* givenString)
{
    long newSize = (StringSize + givenString->length());

    bool result = false;

    char *myBuffer = 0;

    myBuffer = new char[newSize + 1];

    if(myBuffer != 0)
    {
        strcpy(myBuffer, Buffer);
        strcat(myBuffer, givenString->getText());

        if(setText(myBuffer))
        {
            result = true;
        }
    }

    delete myBuffer;

    return result;
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
bool PerlString::operator += (PerlString& givenString)
{
    long newSize = (StringSize + givenString.length());

    bool result = false;

    char *myBuffer = 0;

    myBuffer = new char[newSize + 1];

    if(myBuffer != 0)
    {
        strcpy(myBuffer, Buffer);
        strcat(myBuffer, givenString.getText());

        if(setText(myBuffer))
        {
            result = true;
        }
    }

    delete[] myBuffer;

    return result;
}
// ------------------------------------------------------------------
//  QUALITY CONTROL TAG - END
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  QUALITY METRICS CODE - BEGIN
// ------------------------------------------------------------------
void PerlString::printMemInfo()
{
    cout << "Bytes allocated: " << BytesAllocated << endl;
    cout << "Buffer size:     " << BufferSize << endl;
    return;
}
// ------------------------------------------------------------------
//  QUALITY METRICS CODE - END
// ------------------------------------------------------------------

