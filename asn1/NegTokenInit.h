/*
 * Generated by asn1c-0.9.22.1409 (http://lionet.info/asn1c)
 * From ASN.1 module "SPNEGO"
 * 	found in "spnego.asn1"
 * 	`asn1c -fnative-types -fskeletons-copy -fcompound-names`
 */

#ifndef	_NegTokenInit_H_
#define	_NegTokenInit_H_


#include <asn_application.h>

/* Including external dependencies */
#include "MechTypeList.h"
#include "ContextFlags.h"
#include <OCTET_STRING.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* NegTokenInit */
typedef struct NegTokenInit {
	MechTypeList_t	 mechTypes;
	ContextFlags_t	*reqFlags	/* OPTIONAL */;
	OCTET_STRING_t	*mechToken	/* OPTIONAL */;
	OCTET_STRING_t	*mechListMIC	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NegTokenInit_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NegTokenInit;

#ifdef __cplusplus
}
#endif

#endif	/* _NegTokenInit_H_ */
