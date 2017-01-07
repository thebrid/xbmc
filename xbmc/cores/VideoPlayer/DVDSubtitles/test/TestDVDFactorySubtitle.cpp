/*
 *      Copyright (C) 2017 Team Kodi
 *      http://kodi.tv
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Kodi; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include "cores/VideoPlayer/DVDSubtitles/DVDSubtitleParser.h"
#include "cores/VideoPlayer/DVDSubtitles/DVDSubtitleParserMicroDVD.h"
#include "cores/VideoPlayer/DVDSubtitles/DVDSubtitleParserMPL2.h"
#include "cores/VideoPlayer/DVDSubtitles/DVDSubtitleParserSami.h"
#include "cores/VideoPlayer/DVDSubtitles/DVDSubtitleParserSSA.h"
#include "cores/VideoPlayer/DVDSubtitles/DVDSubtitleParserSubrip.h"
#include "cores/VideoPlayer/DVDSubtitles/DVDSubtitleParserVplayer.h"
#include "cores/VideoPlayer/DVDSubtitles/DVDFactorySubtitle.h"

#include "gtest/gtest.h"

TEST(DVDFactorySubtitle, NonExistentFileReturnsNull)
{
	std::string fileName("Non-Existent File");
	std::unique_ptr<CDVDSubtitleParser> parser(CDVDFactorySubtitle::CreateParser(fileName));
	EXPECT_EQ(nullptr, parser);
}

TEST(DVDFactorySubtitle, MicroDVDReturnsCorrectParser)
{
	std::string fileName("xbmc/cores/VideoPlayer/DVDSubtitles/test/SampleSubtitle.sub");
	std::unique_ptr<CDVDSubtitleParser> parser(CDVDFactorySubtitle::CreateParser(fileName));
	EXPECT_NE(nullptr, dynamic_cast<CDVDSubtitleParserMicroDVD *>(parser.get()));
}

TEST(DVDFactorySubtitle, MPL2ReturnsCorrectParser)
{
	std::string fileName("xbmc/cores/VideoPlayer/DVDSubtitles/test/SampleSubtitle.mpl");
	std::unique_ptr<CDVDSubtitleParser> parser(CDVDFactorySubtitle::CreateParser(fileName));
	EXPECT_NE(nullptr, dynamic_cast<CDVDSubtitleParserMPL2 *>(parser.get()));
}

TEST(DVDFactorySubtitle, SubripReturnsCorrectParser)
{
	std::string fileName("xbmc/cores/VideoPlayer/DVDSubtitles/test/SampleSubtitle.srt");
	std::unique_ptr<CDVDSubtitleParser> parser(CDVDFactorySubtitle::CreateParser(fileName));
	EXPECT_NE(nullptr, dynamic_cast<CDVDSubtitleParserSubrip *>(parser.get()));
}

TEST(DVDFactorySubtitle, VPlayerReturnsCorrectParser)
{
	std::string fileName("xbmc/cores/VideoPlayer/DVDSubtitles/test/SampleSubtitle.txt");
	std::unique_ptr<CDVDSubtitleParser> parser(CDVDFactorySubtitle::CreateParser(fileName));
	EXPECT_NE(nullptr, dynamic_cast<CDVDSubtitleParserVplayer *>(parser.get()));
}

TEST(DVDFactorySubtitle, SSAReturnsCorrectParser)
{
	std::string fileName("xbmc/cores/VideoPlayer/DVDSubtitles/test/SampleSubtitle.ssa");
	std::unique_ptr<CDVDSubtitleParser> parser(CDVDFactorySubtitle::CreateParser(fileName));
	EXPECT_NE(nullptr, dynamic_cast<CDVDSubtitleParserSSA *>(parser.get()));
}

TEST(DVDFactorySubtitle, SAMIReturnsCorrectParser)
{
	std::string fileName("xbmc/cores/VideoPlayer/DVDSubtitles/test/SampleSubtitle.smi");
	std::unique_ptr<CDVDSubtitleParser> parser(CDVDFactorySubtitle::CreateParser(fileName));
	EXPECT_NE(nullptr, dynamic_cast<CDVDSubtitleParserSami *>(parser.get()));
}

