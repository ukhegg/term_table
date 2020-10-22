//
// Created by ukhegg on 23.10.2020.
//

#pragma once


// Generic helper definitions for shared library support
#if defined _WIN32 || defined __CYGWIN__
#define TERM_TABLE_HELPER_DLL_IMPORT __declspec(dllimport)
#define TERM_TABLE_HELPER_DLL_EXPORT __declspec(dllexport)
#define TERM_TABLE_HELPER_DLL_LOCAL
#else
#if __GNUC__ >= 4
#define TERM_TABLE_HELPER_DLL_IMPORT __attribute__ ((visibility ("default")))
#define TERM_TABLE_HELPER_DLL_EXPORT __attribute__ ((visibility ("default")))
#define TERM_TABLE_HELPER_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
#else
#define TERM_TABLE_HELPER_DLL_IMPORT
#define TERM_TABLE_HELPER_DLL_EXPORT
#define TERM_TABLE_HELPER_DLL_LOCAL
#endif
#endif

// Now we use the generic helper definitions above to define TERM_TABLE_API and TERM_TABLE_LOCAL.
// TERM_TABLE_API is used for the public API symbols. It either DLL imports or DLL exports (or does nothing for static build)
// TERM_TABLE_LOCAL is used for non-api symbols.

#ifdef TERM_TABLE_DLL // defined if TERM_TABLE is compiled as a DLL
#ifdef TERM_TABLE_DLL_EXPORTS // defined if we are building the TERM_TABLE DLL (instead of using it)
#define TERM_TABLE_API TERM_TABLE_HELPER_DLL_EXPORT
#else
#define TERM_TABLE_API TERM_TABLE_HELPER_DLL_IMPORT
#endif // TERM_TABLE_DLL_EXPORTS
#define TERM_TABLE_LOCAL TERM_TABLE_HELPER_DLL_LOCAL
#else // TERM_TABLE_DLL is not defined: this means TERM_TABLE is a static lib.
#define TERM_TABLE_API
#define TERM_TABLE_LOCAL
#endif // TERM_TABLE_DLL
