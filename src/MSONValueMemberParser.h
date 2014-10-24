//
//  MSONValueMemberParser.h
//  snowcrash
//
//  Created by Pavan Kumar Sunkara on 10/22/14.
//  Copyright (c) 2014 Apiary Inc. All rights reserved.
//

#ifndef SNOWCRASH_MSONVALUEMEMBERPARSER_H
#define SNOWCRASH_MSONVALUEMEMBERPARSER_H

#include "SectionParser.h"
#include "MSONUtility.h"

using namespace scpl;

namespace snowcrash {

    /**
     * MSON Value Member Section Processor
     */
    template<>
    struct SectionProcessor<mson::ValueMember> : public SignatureSectionProcessorBase<mson::ValueMember> {

        static SignatureTraits signatureTraits() {

            SignatureTraits signatureTraits(SignatureTraits::ValuesTrait |
                                            SignatureTraits::AttributesTrait |
                                            SignatureTraits::ContentTrait);

            return signatureTraits;
        }

        static void finalizeSignature(const MarkdownNodeIterator& node,
                                      SectionParserData& pd,
                                      const Signature& signature,
                                      const ParseResultRef<mson::ValueMember>& out) {

            out.node.description = signature.content;
        }
    };

    /** MSON Value Member Section Parser */
    typedef SectionParser<mson::ValueMember, ListSectionAdapter> MSONValueMemberParser;
}

#endif
