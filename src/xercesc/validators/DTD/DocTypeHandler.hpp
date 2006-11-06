/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * $Id$
 */



#if !defined(DOCTYPEHANDLER_HPP)
#define DOCTYPEHANDLER_HPP

#include <xercesc/util/XercesDefs.hpp>
#include <xercesc/framework/XMLNotationDecl.hpp>
#include <xercesc/validators/DTD/DTDAttDef.hpp>
#include <xercesc/validators/DTD/DTDElementDecl.hpp>
#include <xercesc/validators/DTD/DTDEntityDecl.hpp>

XERCES_CPP_NAMESPACE_BEGIN

//
//  This abstract class defines the document type handler API's which can be
//  used to process the DTD events generated by the DTDScanner as it scans the
//  internal and external subset.

class VALIDATORS_EXPORT DocTypeHandler
{
public:
    // -----------------------------------------------------------------------
    //  Constructors and Destructor
    // -----------------------------------------------------------------------
    DocTypeHandler()
    {
    }

    virtual ~DocTypeHandler()
    {
    }


    // -----------------------------------------------------------------------
    //  The document type handler virtual handler interface
    // -----------------------------------------------------------------------
    virtual void attDef
    (
        const   DTDElementDecl&     elemDecl
        , const DTDAttDef&          attDef
        , const bool                ignoring
    ) = 0;

    virtual void doctypeComment
    (
        const   XMLCh* const    comment
    ) = 0;

    virtual void doctypeDecl
    (
        const   DTDElementDecl& elemDecl
        , const XMLCh* const    publicId
        , const XMLCh* const    systemId
        , const bool            hasIntSubset
        , const bool            hasExtSubset = false
    ) = 0;

    virtual void doctypePI
    (
        const   XMLCh* const    target
        , const XMLCh* const    data
    ) = 0;

    virtual void doctypeWhitespace
    (
        const   XMLCh* const    chars
        , const unsigned int    length
    ) = 0;

    virtual void elementDecl
    (
        const   DTDElementDecl& decl
        , const bool            isIgnored
    ) = 0;

    virtual void endAttList
    (
        const   DTDElementDecl& elemDecl
    ) = 0;

    virtual void endIntSubset() = 0;

    virtual void endExtSubset() = 0;

    virtual void entityDecl
    (
        const   DTDEntityDecl&  entityDecl
        , const bool            isPEDecl
        , const bool            isIgnored
    ) = 0;

    virtual void resetDocType() = 0;

    virtual void notationDecl
    (
        const   XMLNotationDecl&    notDecl
        , const bool                isIgnored
    ) = 0;

    virtual void startAttList
    (
        const   DTDElementDecl& elemDecl
    ) = 0;

    virtual void startIntSubset() = 0;

    virtual void startExtSubset() = 0;

    virtual void TextDecl
    (
        const   XMLCh* const    versionStr
        , const XMLCh* const    encodingStr
    ) = 0;


private:
    // -----------------------------------------------------------------------
    //  Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    DocTypeHandler(const DocTypeHandler&);
    DocTypeHandler& operator=(const DocTypeHandler&);
};

XERCES_CPP_NAMESPACE_END

#endif
