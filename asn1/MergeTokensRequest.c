/*
 * Generated by asn1c-0.9.22.1409 (http://lionet.info/asn1c)
 * From ASN.1 module "MCS-PROTOCOL-3"
 * 	found in "mcs.asn1"
 * 	`asn1c -fnative-types -fskeletons-copy -fcompound-names -gen-PER`
 */

#include <asn_internal.h>

#include "MergeTokensRequest.h"

static asn_TYPE_member_t asn_MBR_mergeTokens_2[] = {
	{ ATF_POINTER, 0, 0,
		-1 /* Ambiguous tag (CHOICE?) */,
		0,
		&asn_DEF_TokenAttributes,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		""
		},
};
static ber_tlv_tag_t asn_DEF_mergeTokens_tags_2[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (17 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_mergeTokens_specs_2 = {
	sizeof(struct MergeTokensRequest__mergeTokens),
	offsetof(struct MergeTokensRequest__mergeTokens, _asn_ctx),
	2,	/* XER encoding is XMLValueList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_mergeTokens_2 = {
	"mergeTokens",
	"mergeTokens",
	SET_OF_free,
	SET_OF_print,
	SET_OF_constraint,
	SET_OF_decode_ber,
	SET_OF_encode_der,
	SET_OF_decode_xer,
	SET_OF_encode_xer,
	SET_OF_decode_uper,
	SET_OF_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_mergeTokens_tags_2,
	sizeof(asn_DEF_mergeTokens_tags_2)
		/sizeof(asn_DEF_mergeTokens_tags_2[0]) - 1, /* 1 */
	asn_DEF_mergeTokens_tags_2,	/* Same as above */
	sizeof(asn_DEF_mergeTokens_tags_2)
		/sizeof(asn_DEF_mergeTokens_tags_2[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_mergeTokens_2,
	1,	/* Single element */
	&asn_SPC_mergeTokens_specs_2	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_purgeTokenIds_4[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
		0,
		&asn_DEF_TokenId,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		""
		},
};
static ber_tlv_tag_t asn_DEF_purgeTokenIds_tags_4[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (17 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_purgeTokenIds_specs_4 = {
	sizeof(struct MergeTokensRequest__purgeTokenIds),
	offsetof(struct MergeTokensRequest__purgeTokenIds, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_purgeTokenIds_4 = {
	"purgeTokenIds",
	"purgeTokenIds",
	SET_OF_free,
	SET_OF_print,
	SET_OF_constraint,
	SET_OF_decode_ber,
	SET_OF_encode_der,
	SET_OF_decode_xer,
	SET_OF_encode_xer,
	SET_OF_decode_uper,
	SET_OF_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_purgeTokenIds_tags_4,
	sizeof(asn_DEF_purgeTokenIds_tags_4)
		/sizeof(asn_DEF_purgeTokenIds_tags_4[0]) - 1, /* 1 */
	asn_DEF_purgeTokenIds_tags_4,	/* Same as above */
	sizeof(asn_DEF_purgeTokenIds_tags_4)
		/sizeof(asn_DEF_purgeTokenIds_tags_4[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_purgeTokenIds_4,
	1,	/* Single element */
	&asn_SPC_purgeTokenIds_specs_4	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_nonStandard_6[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_NonStandardParameter,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		""
		},
};
static ber_tlv_tag_t asn_DEF_nonStandard_tags_6[] = {
	(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_nonStandard_specs_6 = {
	sizeof(struct MergeTokensRequest__nonStandard),
	offsetof(struct MergeTokensRequest__nonStandard, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_nonStandard_6 = {
	"nonStandard",
	"nonStandard",
	SEQUENCE_OF_free,
	SEQUENCE_OF_print,
	SEQUENCE_OF_constraint,
	SEQUENCE_OF_decode_ber,
	SEQUENCE_OF_encode_der,
	SEQUENCE_OF_decode_xer,
	SEQUENCE_OF_encode_xer,
	SEQUENCE_OF_decode_uper,
	SEQUENCE_OF_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_nonStandard_tags_6,
	sizeof(asn_DEF_nonStandard_tags_6)
		/sizeof(asn_DEF_nonStandard_tags_6[0]) - 1, /* 1 */
	asn_DEF_nonStandard_tags_6,	/* Same as above */
	sizeof(asn_DEF_nonStandard_tags_6)
		/sizeof(asn_DEF_nonStandard_tags_6[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_nonStandard_6,
	1,	/* Single element */
	&asn_SPC_nonStandard_specs_6	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_MergeTokensRequest_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct MergeTokensRequest, mergeTokens),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		0,
		&asn_DEF_mergeTokens_2,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"mergeTokens"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct MergeTokensRequest, purgeTokenIds),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		0,
		&asn_DEF_purgeTokenIds_4,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"purgeTokenIds"
		},
	{ ATF_POINTER, 1, offsetof(struct MergeTokensRequest, nonStandard),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		0,
		&asn_DEF_nonStandard_6,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"nonStandard"
		},
};
static int asn_MAP_MergeTokensRequest_oms_1[] = { 2 };
static ber_tlv_tag_t asn_DEF_MergeTokensRequest_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_MergeTokensRequest_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* mergeTokens at 226 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* purgeTokenIds at 227 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* nonStandard at 228 */
};
static asn_SEQUENCE_specifics_t asn_SPC_MergeTokensRequest_specs_1 = {
	sizeof(struct MergeTokensRequest),
	offsetof(struct MergeTokensRequest, _asn_ctx),
	asn_MAP_MergeTokensRequest_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_MergeTokensRequest_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	2,	/* Start extensions */
	4	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_MergeTokensRequest = {
	"MergeTokensRequest",
	"MergeTokensRequest",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	SEQUENCE_decode_uper,
	SEQUENCE_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_MergeTokensRequest_tags_1,
	sizeof(asn_DEF_MergeTokensRequest_tags_1)
		/sizeof(asn_DEF_MergeTokensRequest_tags_1[0]), /* 1 */
	asn_DEF_MergeTokensRequest_tags_1,	/* Same as above */
	sizeof(asn_DEF_MergeTokensRequest_tags_1)
		/sizeof(asn_DEF_MergeTokensRequest_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_MergeTokensRequest_1,
	3,	/* Elements count */
	&asn_SPC_MergeTokensRequest_specs_1	/* Additional specs */
};

