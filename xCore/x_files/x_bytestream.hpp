//==============================================================================
//  
//  x_bytestream.hpp
//  
//==============================================================================

#ifndef X_BYTESTREAM_HPP
#define X_BYTESTREAM_HPP

//==============================================================================
//  INCLUDES
//==============================================================================

#ifndef X_TYPES_HPP
#include "x_types.hpp"
#endif

#ifndef X_STDIO_HPP
#include "x_stdio.hpp"
#endif

//==============================================================================
//  TYPES
//==============================================================================

//==============================================================================
//  BYTESTREAM
//==============================================================================
//  
//  A simple bytestream class, useful for parsing or building binary files.
//  
//==============================================================================

class xbytestream
{
private:
        void            EnsureCapacity  ( s32 Capacity );

public:
                        xbytestream     ( void );
                        xbytestream     ( const xbytestream& Bytestream );
                        xbytestream     ( const byte* pData, s32 Count );
                       ~xbytestream     ( void );

        s32             GetLength       ( void ) const;

        void            Clear           ( void );
        void            FreeExtra       ( void );

        byte            GetAt           ( s32 Index ) const;
        void            SetAt           ( s32 Index, byte Data );
        byte*           GetBuffer       ( void ) const;

        void            Insert          ( s32 Index, byte Data );
        void            Insert          ( s32 Index, const byte* pData, s32 Count );
        void            Insert          ( s32 Index, const xbytestream& Bytestream );
        void            Delete          ( s32 Index, s32 Count=1 );

        void            Append          ( byte Data );
        void            Append          ( const byte* pData, s32 Count );
        void            Append          ( const xbytestream& Bytestream );

        void            Replace         ( s32 Index, byte Data );
        void            Replace         ( s32 Index, const byte* pData, s32 Count );
        void            Replace         ( s32 Index, const xbytestream& Bytestream );

        s32             Find            ( byte Data, s32 StartIndex=0 ) const;
        s32             Find            ( const xbytestream& Bytestream, s32 StartIndex=0 ) const;

const   xbytestream&    operator =      ( byte               Data );
const   xbytestream&    operator =      ( const xbytestream& Bytestream );
const   xbytestream&    operator +=     ( const xbytestream& Bytestream );
const   xbytestream&    operator +=     ( byte               Data       );

const   xbytestream&    operator <<     ( u8    Data );
const   xbytestream&    operator <<     ( s8    Data );
const   xbytestream&    operator <<     ( u16   Data );
const   xbytestream&    operator <<     ( s16   Data );
const   xbytestream&    operator <<     ( u32   Data );
const   xbytestream&    operator <<     ( s32   Data );

        xbool           LoadFile        ( X_FILE* pFile, s32 Size );
        xbool           SaveFile        ( X_FILE* pFile ) const;
        xbool           LoadFile        ( const char* pFileName );
        xbool           SaveFile        ( const char* pFileName ) const;

protected:
        byte*       m_pData;
};

//==============================================================================
#endif // X_BYTESTREAM_HPP
//==============================================================================