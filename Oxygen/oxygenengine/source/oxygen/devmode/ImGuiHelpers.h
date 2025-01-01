﻿/*
*	Part of the Oxygen Engine / Sonic 3 A.I.R. software distribution.
*	Copyright (C) 2017-2025 by Eukaryot
*
*	Published under the GNU GPLv3 open source software license, see license.txt
*	or https://www.gnu.org/licenses/gpl-3.0.en.html
*/

#pragma once

#include "oxygen/devmode/ImGuiDefinitions.h"

#if defined(SUPPORT_IMGUI)

namespace ImGuiHelpers
{

	struct ScopedIndent
	{
	public:
		inline ScopedIndent(float indent = 12.0f) :
			mIndent(indent)
		{
			ImGui::Indent(mIndent);
		}

		inline ~ScopedIndent()
		{
			ImGui::Unindent(mIndent);
			ImGui::Spacing();
		}

	private:
		float mIndent;
	};


	struct WideInputString
	{
		WString mWideString;
		char mInternalUTF8[256] = { 0 };

		const WString& get() const  { return mWideString; }
		void set(std::wstring_view str);
		void refreshFromInternal();
	};


	struct FilterString
	{
		char mString[256] = { 0 };

		bool draw();
		bool shouldInclude(std::string_view str) const;
	};


	struct OpenCodeLocation
	{
		static bool drawButton();
		static bool drawButton(const std::wstring& path, int lineNumber);
		static bool open(const std::wstring& path, int lineNumber);
	};

}

#endif
