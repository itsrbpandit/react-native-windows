// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.LegacyShadowNode

#pragma once

#include <string>
#include <folly/dynamic.h>

namespace facebook { namespace react {

class IViewManager;

struct LegacyShadowNode
{
	LegacyShadowNode(const LegacyShadowNode& that) = delete;
	LegacyShadowNode& operator=(LegacyShadowNode const&) = delete;
	LegacyShadowNode() = default;
	virtual ~LegacyShadowNode();

	virtual void updateProperties(const folly::dynamic&& props);
	virtual void onDropViewInstance() = 0;
	virtual void dispatchCommand(int64_t commandId, const folly::dynamic& commandArgs);
	virtual void removeAllChildren() = 0;
	virtual void AddView(LegacyShadowNode& child, int64_t index) = 0;
	virtual void RemoveChildAt(int64_t indexToRemove) = 0;
	virtual void createView() = 0;

	int64_t m_tag { 0 };
	std::string m_className;
	std::vector<int64_t> m_children;
	int64_t m_parent = -1;
	IViewManager* m_viewManager = nullptr;
	bool m_zombie = false;
};

}}
