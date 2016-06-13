/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sun Aug 10 04:16:04 2003
 */
/* Compiler settings for C:\Project\WinGraphviz\WinGraphviz.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __WinGraphviz_h__
#define __WinGraphviz_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IBinaryImage_FWD_DEFINED__
#define __IBinaryImage_FWD_DEFINED__
typedef interface IBinaryImage IBinaryImage;
#endif 	/* __IBinaryImage_FWD_DEFINED__ */


#ifndef __IDOT_FWD_DEFINED__
#define __IDOT_FWD_DEFINED__
typedef interface IDOT IDOT;
#endif 	/* __IDOT_FWD_DEFINED__ */


#ifndef __INEATO_FWD_DEFINED__
#define __INEATO_FWD_DEFINED__
typedef interface INEATO INEATO;
#endif 	/* __INEATO_FWD_DEFINED__ */


#ifndef __ITWOPI_FWD_DEFINED__
#define __ITWOPI_FWD_DEFINED__
typedef interface ITWOPI ITWOPI;
#endif 	/* __ITWOPI_FWD_DEFINED__ */


#ifndef __DOT_FWD_DEFINED__
#define __DOT_FWD_DEFINED__

#ifdef __cplusplus
typedef class DOT DOT;
#else
typedef struct DOT DOT;
#endif /* __cplusplus */

#endif 	/* __DOT_FWD_DEFINED__ */


#ifndef __NEATO_FWD_DEFINED__
#define __NEATO_FWD_DEFINED__

#ifdef __cplusplus
typedef class NEATO NEATO;
#else
typedef struct NEATO NEATO;
#endif /* __cplusplus */

#endif 	/* __NEATO_FWD_DEFINED__ */


#ifndef __BinaryImage_FWD_DEFINED__
#define __BinaryImage_FWD_DEFINED__

#ifdef __cplusplus
typedef class BinaryImage BinaryImage;
#else
typedef struct BinaryImage BinaryImage;
#endif /* __cplusplus */

#endif 	/* __BinaryImage_FWD_DEFINED__ */


#ifndef __TWOPI_FWD_DEFINED__
#define __TWOPI_FWD_DEFINED__

#ifdef __cplusplus
typedef class TWOPI TWOPI;
#else
typedef struct TWOPI TWOPI;
#endif /* __cplusplus */

#endif 	/* __TWOPI_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_WinGraphviz_0000 */
/* [local] */ 

typedef 
enum GraphvizTypeIndex
    {	GRAPHVIZ_ATTRIBUTED_DOT	= 0,
	GRAPHVIZ_PS	= 1,
	GRAPHVIZ_PLAIN	= 6,
	GRAPHVIZ_PLAIN_EXT	= 7,
	GRAPHVIZ_GIF	= 11,
	GRAPHVIZ_JPEG	= 12,
	GRAPHVIZ_PNG	= 13,
	GRAPHVIZ_WBMP	= 14,
	GRAPHVIZ_ISMAP	= 16,
	GRAPHVIZ_IMAP	= 17,
	GRAPHVIZ_CMAP	= 18,
	GRAPHVIZ_VRML	= 19,
	GRAPHVIZ_SVG	= 23,
	GRAPHVIZ_SVGZ	= 24,
	GRAPHVIZ_CANONICAL_DOT	= 25,
	GRAPHVIZ_EMF	= 27
    }	GraphvizTypeIndex;



extern RPC_IF_HANDLE __MIDL_itf_WinGraphviz_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_WinGraphviz_0000_v0_0_s_ifspec;

#ifndef __IBinaryImage_INTERFACE_DEFINED__
#define __IBinaryImage_INTERFACE_DEFINED__

/* interface IBinaryImage */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IBinaryImage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FFF6CEBE-BD9B-4C3A-A274-12E600B6BD10")
    IBinaryImage : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( 
            /* [in] */ BSTR FilePath,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Dump( 
            /* [in] */ IStream __RPC_FAR *stream,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Picture( 
            /* [retval][out] */ IPictureDisp __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToBase64String( 
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBinaryImageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IBinaryImage __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IBinaryImage __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IBinaryImage __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IBinaryImage __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IBinaryImage __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IBinaryImage __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IBinaryImage __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Save )( 
            IBinaryImage __RPC_FAR * This,
            /* [in] */ BSTR FilePath,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Dump )( 
            IBinaryImage __RPC_FAR * This,
            /* [in] */ IStream __RPC_FAR *stream,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Result);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Type )( 
            IBinaryImage __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Picture )( 
            IBinaryImage __RPC_FAR * This,
            /* [retval][out] */ IPictureDisp __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToBase64String )( 
            IBinaryImage __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        END_INTERFACE
    } IBinaryImageVtbl;

    interface IBinaryImage
    {
        CONST_VTBL struct IBinaryImageVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBinaryImage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBinaryImage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBinaryImage_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBinaryImage_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IBinaryImage_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IBinaryImage_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IBinaryImage_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IBinaryImage_Save(This,FilePath,Result)	\
    (This)->lpVtbl -> Save(This,FilePath,Result)

#define IBinaryImage_Dump(This,stream,Result)	\
    (This)->lpVtbl -> Dump(This,stream,Result)

#define IBinaryImage_get_Type(This,pVal)	\
    (This)->lpVtbl -> get_Type(This,pVal)

#define IBinaryImage_get_Picture(This,pVal)	\
    (This)->lpVtbl -> get_Picture(This,pVal)

#define IBinaryImage_ToBase64String(This,Result)	\
    (This)->lpVtbl -> ToBase64String(This,Result)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBinaryImage_Save_Proxy( 
    IBinaryImage __RPC_FAR * This,
    /* [in] */ BSTR FilePath,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Result);


void __RPC_STUB IBinaryImage_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBinaryImage_Dump_Proxy( 
    IBinaryImage __RPC_FAR * This,
    /* [in] */ IStream __RPC_FAR *stream,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Result);


void __RPC_STUB IBinaryImage_Dump_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IBinaryImage_get_Type_Proxy( 
    IBinaryImage __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IBinaryImage_get_Type_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IBinaryImage_get_Picture_Proxy( 
    IBinaryImage __RPC_FAR * This,
    /* [retval][out] */ IPictureDisp __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IBinaryImage_get_Picture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBinaryImage_ToBase64String_Proxy( 
    IBinaryImage __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB IBinaryImage_ToBase64String_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IBinaryImage_INTERFACE_DEFINED__ */


#ifndef __IDOT_INTERFACE_DEFINED__
#define __IDOT_INTERFACE_DEFINED__

/* interface IDOT */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDOT;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A1080582-D33F-486E-BD5F-581989A3C7E9")
    IDOT : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToTextGraph( 
            /* [in] */ BSTR Source,
            /* [in] */ long Type,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToDot( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToCanon( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToPlain( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToPlainExt( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToSvg( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Validate( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToPS( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToGIF( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToPNG( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToSVGZ( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToVRML( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToBinaryGraph( 
            /* [in] */ BSTR Source,
            /* [in] */ long Type,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToCMAP( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToIMAP( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToISMAP( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToWBMP( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToJPEG( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Codepage( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Codepage( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToEMF( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDOTVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDOT __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDOT __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDOT __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IDOT __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IDOT __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IDOT __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IDOT __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToTextGraph )( 
            IDOT __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [in] */ long Type,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToDot )( 
            IDOT __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToCanon )( 
            IDOT __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToPlain )( 
            IDOT __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToPlainExt )( 
            IDOT __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToSvg )( 
            IDOT __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Validate )( 
            IDOT __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToPS )( 
            IDOT __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToGIF )( 
            IDOT __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToPNG )( 
            IDOT __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToSVGZ )( 
            IDOT __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToVRML )( 
            IDOT __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToBinaryGraph )( 
            IDOT __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [in] */ long Type,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToCMAP )( 
            IDOT __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToIMAP )( 
            IDOT __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToISMAP )( 
            IDOT __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToWBMP )( 
            IDOT __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToJPEG )( 
            IDOT __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Codepage )( 
            IDOT __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Codepage )( 
            IDOT __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToEMF )( 
            IDOT __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);
        
        END_INTERFACE
    } IDOTVtbl;

    interface IDOT
    {
        CONST_VTBL struct IDOTVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDOT_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDOT_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDOT_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDOT_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDOT_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDOT_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDOT_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDOT_ToTextGraph(This,Source,Type,Result)	\
    (This)->lpVtbl -> ToTextGraph(This,Source,Type,Result)

#define IDOT_ToDot(This,Source,Result)	\
    (This)->lpVtbl -> ToDot(This,Source,Result)

#define IDOT_ToCanon(This,Source,Result)	\
    (This)->lpVtbl -> ToCanon(This,Source,Result)

#define IDOT_ToPlain(This,Source,Result)	\
    (This)->lpVtbl -> ToPlain(This,Source,Result)

#define IDOT_ToPlainExt(This,Source,Result)	\
    (This)->lpVtbl -> ToPlainExt(This,Source,Result)

#define IDOT_ToSvg(This,Source,Result)	\
    (This)->lpVtbl -> ToSvg(This,Source,Result)

#define IDOT_Validate(This,Source,Result)	\
    (This)->lpVtbl -> Validate(This,Source,Result)

#define IDOT_ToPS(This,Source,Result)	\
    (This)->lpVtbl -> ToPS(This,Source,Result)

#define IDOT_ToGIF(This,Source,Result)	\
    (This)->lpVtbl -> ToGIF(This,Source,Result)

#define IDOT_ToPNG(This,Source,Result)	\
    (This)->lpVtbl -> ToPNG(This,Source,Result)

#define IDOT_ToSVGZ(This,Source,Result)	\
    (This)->lpVtbl -> ToSVGZ(This,Source,Result)

#define IDOT_ToVRML(This,Source,Result)	\
    (This)->lpVtbl -> ToVRML(This,Source,Result)

#define IDOT_ToBinaryGraph(This,Source,Type,Result)	\
    (This)->lpVtbl -> ToBinaryGraph(This,Source,Type,Result)

#define IDOT_ToCMAP(This,Source,Result)	\
    (This)->lpVtbl -> ToCMAP(This,Source,Result)

#define IDOT_ToIMAP(This,Source,Result)	\
    (This)->lpVtbl -> ToIMAP(This,Source,Result)

#define IDOT_ToISMAP(This,Source,Result)	\
    (This)->lpVtbl -> ToISMAP(This,Source,Result)

#define IDOT_ToWBMP(This,Source,Result)	\
    (This)->lpVtbl -> ToWBMP(This,Source,Result)

#define IDOT_ToJPEG(This,Source,Result)	\
    (This)->lpVtbl -> ToJPEG(This,Source,Result)

#define IDOT_get_Codepage(This,pVal)	\
    (This)->lpVtbl -> get_Codepage(This,pVal)

#define IDOT_put_Codepage(This,newVal)	\
    (This)->lpVtbl -> put_Codepage(This,newVal)

#define IDOT_ToEMF(This,Source,Result)	\
    (This)->lpVtbl -> ToEMF(This,Source,Result)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDOT_ToTextGraph_Proxy( 
    IDOT __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [in] */ long Type,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB IDOT_ToTextGraph_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDOT_ToDot_Proxy( 
    IDOT __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB IDOT_ToDot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDOT_ToCanon_Proxy( 
    IDOT __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB IDOT_ToCanon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDOT_ToPlain_Proxy( 
    IDOT __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB IDOT_ToPlain_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDOT_ToPlainExt_Proxy( 
    IDOT __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB IDOT_ToPlainExt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDOT_ToSvg_Proxy( 
    IDOT __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB IDOT_ToSvg_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDOT_Validate_Proxy( 
    IDOT __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Result);


void __RPC_STUB IDOT_Validate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDOT_ToPS_Proxy( 
    IDOT __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB IDOT_ToPS_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDOT_ToGIF_Proxy( 
    IDOT __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);


void __RPC_STUB IDOT_ToGIF_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDOT_ToPNG_Proxy( 
    IDOT __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);


void __RPC_STUB IDOT_ToPNG_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDOT_ToSVGZ_Proxy( 
    IDOT __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);


void __RPC_STUB IDOT_ToSVGZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDOT_ToVRML_Proxy( 
    IDOT __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB IDOT_ToVRML_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDOT_ToBinaryGraph_Proxy( 
    IDOT __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [in] */ long Type,
    /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);


void __RPC_STUB IDOT_ToBinaryGraph_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDOT_ToCMAP_Proxy( 
    IDOT __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB IDOT_ToCMAP_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDOT_ToIMAP_Proxy( 
    IDOT __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB IDOT_ToIMAP_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDOT_ToISMAP_Proxy( 
    IDOT __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB IDOT_ToISMAP_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDOT_ToWBMP_Proxy( 
    IDOT __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);


void __RPC_STUB IDOT_ToWBMP_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDOT_ToJPEG_Proxy( 
    IDOT __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);


void __RPC_STUB IDOT_ToJPEG_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDOT_get_Codepage_Proxy( 
    IDOT __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IDOT_get_Codepage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDOT_put_Codepage_Proxy( 
    IDOT __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IDOT_put_Codepage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDOT_ToEMF_Proxy( 
    IDOT __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);


void __RPC_STUB IDOT_ToEMF_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDOT_INTERFACE_DEFINED__ */


#ifndef __INEATO_INTERFACE_DEFINED__
#define __INEATO_INTERFACE_DEFINED__

/* interface INEATO */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_INEATO;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B41D4C33-882C-4534-8352-EE981323CD96")
    INEATO : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToTextGraph( 
            /* [in] */ BSTR Source,
            /* [in] */ long Type,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToCanon( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToDot( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToPlain( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToPlainExt( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToSvg( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Validate( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToPS( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToGIF( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToPNG( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToSVGZ( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToVRML( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToBinaryGraph( 
            /* [in] */ BSTR Source,
            /* [in] */ long Type,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToCMAP( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToIMAP( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToISMAP( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToWBMP( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToJPEG( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Codepage( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Codepage( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToEMF( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INEATOVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            INEATO __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            INEATO __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            INEATO __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            INEATO __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            INEATO __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            INEATO __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            INEATO __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToTextGraph )( 
            INEATO __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [in] */ long Type,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToCanon )( 
            INEATO __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToDot )( 
            INEATO __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToPlain )( 
            INEATO __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToPlainExt )( 
            INEATO __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToSvg )( 
            INEATO __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Validate )( 
            INEATO __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToPS )( 
            INEATO __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToGIF )( 
            INEATO __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToPNG )( 
            INEATO __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToSVGZ )( 
            INEATO __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToVRML )( 
            INEATO __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToBinaryGraph )( 
            INEATO __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [in] */ long Type,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToCMAP )( 
            INEATO __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToIMAP )( 
            INEATO __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToISMAP )( 
            INEATO __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToWBMP )( 
            INEATO __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToJPEG )( 
            INEATO __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Codepage )( 
            INEATO __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Codepage )( 
            INEATO __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToEMF )( 
            INEATO __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);
        
        END_INTERFACE
    } INEATOVtbl;

    interface INEATO
    {
        CONST_VTBL struct INEATOVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INEATO_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INEATO_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INEATO_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INEATO_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INEATO_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INEATO_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INEATO_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INEATO_ToTextGraph(This,Source,Type,Result)	\
    (This)->lpVtbl -> ToTextGraph(This,Source,Type,Result)

#define INEATO_ToCanon(This,Source,Result)	\
    (This)->lpVtbl -> ToCanon(This,Source,Result)

#define INEATO_ToDot(This,Source,Result)	\
    (This)->lpVtbl -> ToDot(This,Source,Result)

#define INEATO_ToPlain(This,Source,Result)	\
    (This)->lpVtbl -> ToPlain(This,Source,Result)

#define INEATO_ToPlainExt(This,Source,Result)	\
    (This)->lpVtbl -> ToPlainExt(This,Source,Result)

#define INEATO_ToSvg(This,Source,Result)	\
    (This)->lpVtbl -> ToSvg(This,Source,Result)

#define INEATO_Validate(This,Source,Result)	\
    (This)->lpVtbl -> Validate(This,Source,Result)

#define INEATO_ToPS(This,Source,Result)	\
    (This)->lpVtbl -> ToPS(This,Source,Result)

#define INEATO_ToGIF(This,Source,Result)	\
    (This)->lpVtbl -> ToGIF(This,Source,Result)

#define INEATO_ToPNG(This,Source,Result)	\
    (This)->lpVtbl -> ToPNG(This,Source,Result)

#define INEATO_ToSVGZ(This,Source,Result)	\
    (This)->lpVtbl -> ToSVGZ(This,Source,Result)

#define INEATO_ToVRML(This,Source,Result)	\
    (This)->lpVtbl -> ToVRML(This,Source,Result)

#define INEATO_ToBinaryGraph(This,Source,Type,Result)	\
    (This)->lpVtbl -> ToBinaryGraph(This,Source,Type,Result)

#define INEATO_ToCMAP(This,Source,Result)	\
    (This)->lpVtbl -> ToCMAP(This,Source,Result)

#define INEATO_ToIMAP(This,Source,Result)	\
    (This)->lpVtbl -> ToIMAP(This,Source,Result)

#define INEATO_ToISMAP(This,Source,Result)	\
    (This)->lpVtbl -> ToISMAP(This,Source,Result)

#define INEATO_ToWBMP(This,Source,Result)	\
    (This)->lpVtbl -> ToWBMP(This,Source,Result)

#define INEATO_ToJPEG(This,Source,Result)	\
    (This)->lpVtbl -> ToJPEG(This,Source,Result)

#define INEATO_get_Codepage(This,pVal)	\
    (This)->lpVtbl -> get_Codepage(This,pVal)

#define INEATO_put_Codepage(This,newVal)	\
    (This)->lpVtbl -> put_Codepage(This,newVal)

#define INEATO_ToEMF(This,Source,Result)	\
    (This)->lpVtbl -> ToEMF(This,Source,Result)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INEATO_ToTextGraph_Proxy( 
    INEATO __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [in] */ long Type,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB INEATO_ToTextGraph_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INEATO_ToCanon_Proxy( 
    INEATO __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB INEATO_ToCanon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INEATO_ToDot_Proxy( 
    INEATO __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB INEATO_ToDot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INEATO_ToPlain_Proxy( 
    INEATO __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB INEATO_ToPlain_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INEATO_ToPlainExt_Proxy( 
    INEATO __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB INEATO_ToPlainExt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INEATO_ToSvg_Proxy( 
    INEATO __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB INEATO_ToSvg_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INEATO_Validate_Proxy( 
    INEATO __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Result);


void __RPC_STUB INEATO_Validate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INEATO_ToPS_Proxy( 
    INEATO __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB INEATO_ToPS_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INEATO_ToGIF_Proxy( 
    INEATO __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);


void __RPC_STUB INEATO_ToGIF_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INEATO_ToPNG_Proxy( 
    INEATO __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);


void __RPC_STUB INEATO_ToPNG_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INEATO_ToSVGZ_Proxy( 
    INEATO __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);


void __RPC_STUB INEATO_ToSVGZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INEATO_ToVRML_Proxy( 
    INEATO __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB INEATO_ToVRML_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INEATO_ToBinaryGraph_Proxy( 
    INEATO __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [in] */ long Type,
    /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);


void __RPC_STUB INEATO_ToBinaryGraph_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INEATO_ToCMAP_Proxy( 
    INEATO __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB INEATO_ToCMAP_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INEATO_ToIMAP_Proxy( 
    INEATO __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB INEATO_ToIMAP_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INEATO_ToISMAP_Proxy( 
    INEATO __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB INEATO_ToISMAP_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INEATO_ToWBMP_Proxy( 
    INEATO __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);


void __RPC_STUB INEATO_ToWBMP_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INEATO_ToJPEG_Proxy( 
    INEATO __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);


void __RPC_STUB INEATO_ToJPEG_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE INEATO_get_Codepage_Proxy( 
    INEATO __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB INEATO_get_Codepage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE INEATO_put_Codepage_Proxy( 
    INEATO __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB INEATO_put_Codepage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INEATO_ToEMF_Proxy( 
    INEATO __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);


void __RPC_STUB INEATO_ToEMF_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INEATO_INTERFACE_DEFINED__ */


#ifndef __ITWOPI_INTERFACE_DEFINED__
#define __ITWOPI_INTERFACE_DEFINED__

/* interface ITWOPI */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ITWOPI;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B22DD1A2-6884-47AA-9CAA-8E35C1154A5C")
    ITWOPI : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToTextGraph( 
            /* [in] */ BSTR Source,
            /* [in] */ long Type,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToDot( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToCanon( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToPlain( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToPlainExt( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToSvg( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Validate( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToPS( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToGIF( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToPNG( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToSVGZ( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToVRML( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToBinaryGraph( 
            /* [in] */ BSTR Source,
            /* [in] */ long Type,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToCMAP( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToIMAP( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToISMAP( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToWBMP( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToJPEG( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Codepage( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Codepage( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ToEMF( 
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITWOPIVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITWOPI __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITWOPI __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITWOPI __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ITWOPI __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ITWOPI __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ITWOPI __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ITWOPI __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToTextGraph )( 
            ITWOPI __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [in] */ long Type,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToDot )( 
            ITWOPI __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToCanon )( 
            ITWOPI __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToPlain )( 
            ITWOPI __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToPlainExt )( 
            ITWOPI __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToSvg )( 
            ITWOPI __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Validate )( 
            ITWOPI __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToPS )( 
            ITWOPI __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToGIF )( 
            ITWOPI __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToPNG )( 
            ITWOPI __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToSVGZ )( 
            ITWOPI __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToVRML )( 
            ITWOPI __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToBinaryGraph )( 
            ITWOPI __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [in] */ long Type,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToCMAP )( 
            ITWOPI __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToIMAP )( 
            ITWOPI __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToISMAP )( 
            ITWOPI __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ BSTR __RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToWBMP )( 
            ITWOPI __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToJPEG )( 
            ITWOPI __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Codepage )( 
            ITWOPI __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Codepage )( 
            ITWOPI __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ToEMF )( 
            ITWOPI __RPC_FAR * This,
            /* [in] */ BSTR Source,
            /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);
        
        END_INTERFACE
    } ITWOPIVtbl;

    interface ITWOPI
    {
        CONST_VTBL struct ITWOPIVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITWOPI_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITWOPI_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITWOPI_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITWOPI_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ITWOPI_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ITWOPI_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ITWOPI_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ITWOPI_ToTextGraph(This,Source,Type,Result)	\
    (This)->lpVtbl -> ToTextGraph(This,Source,Type,Result)

#define ITWOPI_ToDot(This,Source,Result)	\
    (This)->lpVtbl -> ToDot(This,Source,Result)

#define ITWOPI_ToCanon(This,Source,Result)	\
    (This)->lpVtbl -> ToCanon(This,Source,Result)

#define ITWOPI_ToPlain(This,Source,Result)	\
    (This)->lpVtbl -> ToPlain(This,Source,Result)

#define ITWOPI_ToPlainExt(This,Source,Result)	\
    (This)->lpVtbl -> ToPlainExt(This,Source,Result)

#define ITWOPI_ToSvg(This,Source,Result)	\
    (This)->lpVtbl -> ToSvg(This,Source,Result)

#define ITWOPI_Validate(This,Source,Result)	\
    (This)->lpVtbl -> Validate(This,Source,Result)

#define ITWOPI_ToPS(This,Source,Result)	\
    (This)->lpVtbl -> ToPS(This,Source,Result)

#define ITWOPI_ToGIF(This,Source,Result)	\
    (This)->lpVtbl -> ToGIF(This,Source,Result)

#define ITWOPI_ToPNG(This,Source,Result)	\
    (This)->lpVtbl -> ToPNG(This,Source,Result)

#define ITWOPI_ToSVGZ(This,Source,Result)	\
    (This)->lpVtbl -> ToSVGZ(This,Source,Result)

#define ITWOPI_ToVRML(This,Source,Result)	\
    (This)->lpVtbl -> ToVRML(This,Source,Result)

#define ITWOPI_ToBinaryGraph(This,Source,Type,Result)	\
    (This)->lpVtbl -> ToBinaryGraph(This,Source,Type,Result)

#define ITWOPI_ToCMAP(This,Source,Result)	\
    (This)->lpVtbl -> ToCMAP(This,Source,Result)

#define ITWOPI_ToIMAP(This,Source,Result)	\
    (This)->lpVtbl -> ToIMAP(This,Source,Result)

#define ITWOPI_ToISMAP(This,Source,Result)	\
    (This)->lpVtbl -> ToISMAP(This,Source,Result)

#define ITWOPI_ToWBMP(This,Source,Result)	\
    (This)->lpVtbl -> ToWBMP(This,Source,Result)

#define ITWOPI_ToJPEG(This,Source,Result)	\
    (This)->lpVtbl -> ToJPEG(This,Source,Result)

#define ITWOPI_get_Codepage(This,pVal)	\
    (This)->lpVtbl -> get_Codepage(This,pVal)

#define ITWOPI_put_Codepage(This,newVal)	\
    (This)->lpVtbl -> put_Codepage(This,newVal)

#define ITWOPI_ToEMF(This,Source,Result)	\
    (This)->lpVtbl -> ToEMF(This,Source,Result)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITWOPI_ToTextGraph_Proxy( 
    ITWOPI __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [in] */ long Type,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB ITWOPI_ToTextGraph_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITWOPI_ToDot_Proxy( 
    ITWOPI __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB ITWOPI_ToDot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITWOPI_ToCanon_Proxy( 
    ITWOPI __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB ITWOPI_ToCanon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITWOPI_ToPlain_Proxy( 
    ITWOPI __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB ITWOPI_ToPlain_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITWOPI_ToPlainExt_Proxy( 
    ITWOPI __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB ITWOPI_ToPlainExt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITWOPI_ToSvg_Proxy( 
    ITWOPI __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB ITWOPI_ToSvg_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITWOPI_Validate_Proxy( 
    ITWOPI __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Result);


void __RPC_STUB ITWOPI_Validate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITWOPI_ToPS_Proxy( 
    ITWOPI __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB ITWOPI_ToPS_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITWOPI_ToGIF_Proxy( 
    ITWOPI __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);


void __RPC_STUB ITWOPI_ToGIF_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITWOPI_ToPNG_Proxy( 
    ITWOPI __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);


void __RPC_STUB ITWOPI_ToPNG_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITWOPI_ToSVGZ_Proxy( 
    ITWOPI __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);


void __RPC_STUB ITWOPI_ToSVGZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITWOPI_ToVRML_Proxy( 
    ITWOPI __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB ITWOPI_ToVRML_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITWOPI_ToBinaryGraph_Proxy( 
    ITWOPI __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [in] */ long Type,
    /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);


void __RPC_STUB ITWOPI_ToBinaryGraph_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITWOPI_ToCMAP_Proxy( 
    ITWOPI __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB ITWOPI_ToCMAP_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITWOPI_ToIMAP_Proxy( 
    ITWOPI __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB ITWOPI_ToIMAP_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITWOPI_ToISMAP_Proxy( 
    ITWOPI __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ BSTR __RPC_FAR *Result);


void __RPC_STUB ITWOPI_ToISMAP_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITWOPI_ToWBMP_Proxy( 
    ITWOPI __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);


void __RPC_STUB ITWOPI_ToWBMP_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITWOPI_ToJPEG_Proxy( 
    ITWOPI __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);


void __RPC_STUB ITWOPI_ToJPEG_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ITWOPI_get_Codepage_Proxy( 
    ITWOPI __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB ITWOPI_get_Codepage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ITWOPI_put_Codepage_Proxy( 
    ITWOPI __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB ITWOPI_put_Codepage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITWOPI_ToEMF_Proxy( 
    ITWOPI __RPC_FAR * This,
    /* [in] */ BSTR Source,
    /* [retval][out] */ IBinaryImage __RPC_FAR *__RPC_FAR *Result);


void __RPC_STUB ITWOPI_ToEMF_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITWOPI_INTERFACE_DEFINED__ */



#ifndef __WINGRAPHVIZLib_LIBRARY_DEFINED__
#define __WINGRAPHVIZLib_LIBRARY_DEFINED__

/* library WINGRAPHVIZLib */
/* [helpstring][version][uuid] */ 



EXTERN_C const IID LIBID_WINGRAPHVIZLib;

EXTERN_C const CLSID CLSID_DOT;

#ifdef __cplusplus

class DECLSPEC_UUID("55811839-47B0-4854-81B5-0A0031B8ACEC")
DOT;
#endif

EXTERN_C const CLSID CLSID_NEATO;

#ifdef __cplusplus

class DECLSPEC_UUID("1F25D86C-95BC-4E33-A177-EE8DABEF8B04")
NEATO;
#endif

EXTERN_C const CLSID CLSID_BinaryImage;

#ifdef __cplusplus

class DECLSPEC_UUID("6B3F62C8-80CE-470D-B2E4-0BA42A035228")
BinaryImage;
#endif

EXTERN_C const CLSID CLSID_TWOPI;

#ifdef __cplusplus

class DECLSPEC_UUID("684811FB-0523-420F-9E8F-A5452C65A19C")
TWOPI;
#endif
#endif /* __WINGRAPHVIZLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
