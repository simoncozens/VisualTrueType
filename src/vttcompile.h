// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
#pragma once

class Application
{
public:
	Application(void);
	bool Create();
	virtual ~Application(void);

	bool OpenFont(std::string fileName);
	bool SaveFont(StripCommand strip, wchar_t errMsg[]);
	bool SaveFont(std::string fileName, StripCommand strip, wchar_t errMsg[]);

	bool GotoFont(wchar_t errMsg[]);
	bool GotoGlyph(long code, bool isGlyphIndex);

	bool CompileTalk(long* errPos, long* errLen, wchar_t errMsg[]);
	bool CompileCommon(long* errPos, long* errLen, wchar_t errMsg[]);
	bool CompileGlyphRange(unsigned short g1, unsigned short g2, long* errPos, long* errLen, bool quiet, wchar_t errMsg[]);
	bool CompileAll(long* errPos, long* errLen, bool quiet, wchar_t errMsg[]);

	bool BuildFont(StripCommand strip, wchar_t errMsg[]);

private:

	std::unique_ptr<TextBuffer> glyf = nullptr, prep = nullptr, talk = nullptr, fpgm = nullptr, cpgm = nullptr;
	short platformID = 3, encodingID = 1;

	wchar_t mainFont[maxLineSize], textFont[maxLineSize];

	bool fontOpen = false;
	std::unique_ptr<TrueTypeFont> font = nullptr;
	std::unique_ptr<TrueTypeGlyph> glyph = nullptr;
	std::string fileName;
	long charCode = 0, glyphIndex = 0;

	
};
