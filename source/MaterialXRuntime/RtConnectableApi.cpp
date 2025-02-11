//
// TM & (c) 2019 Lucasfilm Entertainment Company Ltd. and Lucasfilm Ltd.
// All rights reserved.  See LICENSE.txt for license.
//

#include <MaterialXRuntime/RtConnectableApi.h>
#include <MaterialXRuntime/RtPrim.h>

namespace MaterialX
{

namespace
{
    RtStringMap<RtConnectableApiPtr> s_connectableApiRegistry;
}

bool RtConnectableApi::acceptConnection(const RtInput& input, const RtOutput& output) const
{
    // Default implementation checks if the types are matching.
    //
    // TODO: Check if the data types are compatible/castable
    // instead of strictly an exact match.
    //
    return input.getType() == output.getType();
}

bool RtConnectableApi::acceptRelationship(const RtRelationship&, const RtObject&) const
{
    // Default implementation accepts all relationships
    return true;
}

void RtConnectableApi::registerApi(const RtString& typeName, const RtConnectableApiPtr& api)
{
    s_connectableApiRegistry[typeName] = api;
}

void RtConnectableApi::unregisterApi(const RtString& typeName)
{
    s_connectableApiRegistry.erase(typeName);
}

RtConnectableApi* RtConnectableApi::get(const RtPrim& prim)
{
    auto it = s_connectableApiRegistry.find(prim.getTypeName());
    return it != s_connectableApiRegistry.end() ? it->second.get() : nullptr;
}

}
