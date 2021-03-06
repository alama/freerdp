/*
 * Generated by asn1c-0.9.22.1409 (http://lionet.info/asn1c)
 * From ASN.1 module "MCS-PROTOCOL-3"
 * 	found in "mcs.asn1"
 * 	`asn1c -fnative-types -fskeletons-copy -fcompound-names -gen-PER`
 */

#ifndef	_TokenStatus_H_
#define	_TokenStatus_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NULL.h>
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum TokenStatus_PR {
	TokenStatus_PR_NOTHING,	/* No components present */
	TokenStatus_PR_notInUse,
	TokenStatus_PR_selfGrabbed,
	TokenStatus_PR_otherGrabbed,
	TokenStatus_PR_selfInhibited,
	TokenStatus_PR_otherInhibited,
	TokenStatus_PR_selfRecipient,
	TokenStatus_PR_selfGiving,
	TokenStatus_PR_otherGiving,
	/* Extensions may appear below */
	
} TokenStatus_PR;

/* TokenStatus */
typedef struct TokenStatus {
	TokenStatus_PR present;
	union TokenStatus_u {
		NULL_t	 notInUse;
		NULL_t	 selfGrabbed;
		NULL_t	 otherGrabbed;
		NULL_t	 selfInhibited;
		NULL_t	 otherInhibited;
		NULL_t	 selfRecipient;
		NULL_t	 selfGiving;
		NULL_t	 otherGiving;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} TokenStatus_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TokenStatus;

#ifdef __cplusplus
}
#endif

#endif	/* _TokenStatus_H_ */
