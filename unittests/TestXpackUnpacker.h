/* ============================================================================
* Copyright (c) 2012, Sebastian Eschweiler <advanced(dot)malware<dot>analyst[at]gmail.com>
* All rights reserved.
* 
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in the
*       documentation and/or other materials provided with the distribution.
*     * Neither the name of the <organization> nor the
*       names of its contributors may be used to endorse or promote products
*       derived from this software without specific prior written permission.
* 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
* =============================================================================
*/

#include <gtest/gtest.h>
#include <XpackUnpacker.h>
#include <tchar.h>

#include <fstream>
#include <streambuf>

class XpackUnpackerTest : public ::testing::Test
{

public:
	XpackUnpackerTest()
	{
	}

	virtual ~XpackUnpackerTest()
	{}

	virtual void SetUp()
	{}

	virtual void TearDown()
	{}

};


TEST_F(XpackUnpackerTest, testRevealCode1)
{
	unsigned char codeBeforeReveal[] = 
	{
		0xD4, 0xAD, 0xD6, 0xC2, 0xD8, 0xC6, 0xDA, 0xB0, 0x7C, 0xAE, 0x81, 0x7C, 0xF8, 0x0D, 0x7F, 0x7C, 
		0x7A, 0x80, 0x10, 0xF6, 0x97, 0xE6, 0x2D, 0x6C, 0x17, 0x37, 0xAC, 0xCE, 0x4D, 0x68, 0x9E, 0x8F, 
		0xF4, 0xD4, 0x4A, 0x95, 0xE1, 0x4E, 0xC8, 0xC5, 0x32, 0x8A, 0x5F, 0x11, 0x29, 0x2A, 0x11, 0x17, 
		0x5F, 0x5C, 0xEA, 0xF0, 0xD3, 0x31, 0x45, 0x4E, 0x3A, 0x49, 0xFB, 0x3D, 0x64, 0xE0, 0x0E, 0xB4, 
		0x68, 0xEE, 0x95, 0x87, 0xB8, 0xDC, 0x81, 0xEC, 0xFF, 0xE4, 0xC8, 0xBC, 0x1A, 0x51, 0xFB, 0x7F, 
		0x20, 0x3D, 0x9E, 0xD7, 0x12, 0x45, 0x2D, 0x23, 0xB4, 0x50, 0xF6, 0xF4, 0xB0, 0x8D, 0xF2, 0xFF, 
		0x6D, 0x53, 0x9D, 0x5D, 0x39, 0xF3, 0x81, 0x39, 0x18, 0xCF, 0x1C, 0xA1, 0x49, 0x70, 0xAE, 0x96, 
		0x73, 0xBF, 0x17, 0x45, 0x61, 0x71, 0x3A, 0xE7, 0x78, 0x1C, 0x59, 0xFA, 0x5E, 0x75, 0xFD, 0x49, 
		0xE6, 0xA6, 0xF2, 0x25, 0x22, 0x2B, 0x83, 0xE1, 0xE6, 0xD1, 0xC1, 0xC4, 0xDD, 0x37, 0xAD, 0x45, 
		0xF9, 0x6A, 0xCC, 0x87, 0x13, 0xCF, 0xD5, 0xA6, 0x62, 0x6B, 0x17, 0xEE, 0x68, 0xDA, 0xDB, 0x52, 
		0x71, 0x61, 0xD4, 0x89, 0x70, 0x50, 0x38, 0x1F, 0xB9, 0xBE, 0x7C, 0x7A, 0xAC, 0x3C, 0x10, 0x5C, 
		0x0F, 0x87, 0x2C, 0x90, 0x39, 0x20, 0x4D, 0xB2, 0x52, 0x3C, 0x64, 0xCD, 0xD1, 0xC8, 0x78, 0x1A, 
		0x53, 0x31, 0xAE, 0x93, 0x1F, 0x91, 0x5D, 0x24, 0x5A, 0x58, 0x50, 0xF2, 0xA7, 0x7A, 0xB2, 0x40, 
		0x48, 0xC3, 0x39, 0xE5, 0x3F, 0x09, 0xF5, 0xDC, 0x7B, 0x1C, 0x41, 0x48, 0xA6, 0x42, 0xA8, 0x04, 
		0x63, 0x22, 0xBB, 0x1F, 0x01, 0x36, 0x27, 0xBE, 0x62, 0xC2, 0x7A, 0xC9, 0x34, 0xF5, 0x60, 0xDF, 
		0x1A, 0x9C, 0xB3, 0x28, 0x96, 0xF2, 0x04, 0x7A, 0x47, 0x7C, 0x71, 0x65, 0x67, 0x94, 0xF0, 0xF8
	};

	unsigned char CorrectCodeAfterReveal[] = 
	{
		0xD2, 0xAA, 0xD2, 0xBD, 0xD2, 0xBF, 0xD2, 0xA7, 0x7A, 0xAC, 0x7F, 0x7A, 0xF6, 0x0B, 0x7D, 0x7A, 
		0x7A, 0x80, 0x10, 0xF6, 0x97, 0xE6, 0x2D, 0x6C, 0x17, 0x37, 0xAC, 0xCE, 0x4D, 0x68, 0x9E, 0x8F, 
		0xF4, 0xD4, 0x4A, 0x95, 0xE1, 0x4E, 0xC8, 0xC5, 0x32, 0x8A, 0x5F, 0x11, 0x29, 0x2A, 0x11, 0x17, 
		0x5F, 0x5C, 0xEA, 0xF0, 0xD3, 0x31, 0x45, 0x4E, 0x3A, 0x49, 0xFB, 0x3D, 0x64, 0xE0, 0x0E, 0xB4, 
		0x66, 0xEB, 0x91, 0x82, 0xB2, 0xD5, 0x79, 0xE3, 0xFD, 0xE2, 0xC6, 0xBA, 0x18, 0x4F, 0xF9, 0x7D, 
		0x20, 0x3D, 0x9E, 0xD7, 0x12, 0x45, 0x2D, 0x23, 0xB4, 0x50, 0xF6, 0xF4, 0xB0, 0x8D, 0xF2, 0xFF, 
		0x6D, 0x53, 0x9D, 0x5D, 0x39, 0xF3, 0x81, 0x39, 0x18, 0xCF, 0x1C, 0xA1, 0x49, 0x70, 0xAE, 0x96, 
		0x73, 0xBF, 0x17, 0x45, 0x61, 0x71, 0x3A, 0xE7, 0x78, 0x1C, 0x59, 0xFA, 0x5E, 0x75, 0xFD, 0x49, 
		0xE4, 0xA3, 0xEE, 0x20, 0x1C, 0x24, 0x7B, 0xD8, 0xE4, 0xCF, 0xBF, 0xC2, 0xDB, 0x35, 0xAB, 0x43, 
		0xF9, 0x6A, 0xCC, 0x87, 0x13, 0xCF, 0xD5, 0xA6, 0x62, 0x6B, 0x17, 0xEE, 0x68, 0xDA, 0xDB, 0x52, 
		0x71, 0x61, 0xD4, 0x89, 0x70, 0x50, 0x38, 0x1F, 0xB9, 0xBE, 0x7C, 0x7A, 0xAC, 0x3C, 0x10, 0x5C, 
		0x0F, 0x87, 0x2C, 0x90, 0x39, 0x20, 0x4D, 0xB2, 0x52, 0x3C, 0x64, 0xCD, 0xD1, 0xC8, 0x78, 0x1A, 
		0x51, 0x2E, 0xAA, 0x8E, 0x19, 0x8A, 0x55, 0x1B, 0x58, 0x56, 0x4E, 0xF0, 0xA5, 0x78, 0xB0, 0x3E, 
		0x48, 0xC3, 0x39, 0xE5, 0x3F, 0x09, 0xF5, 0xDC, 0x7B, 0x1C, 0x41, 0x48, 0xA6, 0x42, 0xA8, 0x04, 
		0x63, 0x22, 0xBB, 0x1F, 0x01, 0x36, 0x27, 0xBE, 0x62, 0xC2, 0x7A, 0xC9, 0x34, 0xF5, 0x60, 0xDF, 
		0x1A, 0x9C, 0xB3, 0x28, 0x96, 0xF2, 0x04, 0x7A, 0x47, 0x7C, 0x71, 0x65, 0x67, 0x94, 0xF0, 0xF8, 
	};

	XPackUnpacker::decryptStage2a(codeBeforeReveal, sizeof codeBeforeReveal);
	ASSERT_EQ(memcmp(codeBeforeReveal, CorrectCodeAfterReveal, sizeof codeBeforeReveal), 0);


}


TEST_F(XpackUnpackerTest, testRevealCode2)
{

	basic_ifstream<unsigned char> t("testfiles/427b7b708de8436d73cbbfd645099416/3base64Unpacked.bin", ios::binary);
	ustring unpackedBase64((istreambuf_iterator<unsigned char>(t)), istreambuf_iterator<unsigned char>());

	XPackUnpacker::decryptStage2a(const_cast<unsigned char*>(unpackedBase64.c_str()), (DWORD) unpackedBase64.length());

	t = basic_ifstream<unsigned char>("testfiles/427b7b708de8436d73cbbfd645099416/4packedCodeRevealed_BeforeRevealXPACK.bin", ios::binary);
	ustring revealed((istreambuf_iterator<unsigned char>(t)), istreambuf_iterator<unsigned char>());

	ASSERT_EQ(revealed, unpackedBase64);

}


TEST_F(XpackUnpackerTest, testIsPackedByXpack)
{
	basic_ifstream<unsigned char> t("testfiles/d5b0a448f59c3e946255333ad0ef5cc5/d5b0a448f59c3e946255333ad0ef5cc5", ios::binary);
	ustring sample((istreambuf_iterator<unsigned char>(t)), istreambuf_iterator<unsigned char>());
	ASSERT_TRUE(XPackUnpacker::isPackedByXpack(sample));

	// notepad.exe
	t = basic_ifstream<unsigned char>("testfiles/d378bffb70923139d6a4f546864aa61c", ios::binary); 
	sample = ustring((istreambuf_iterator<unsigned char>(t)), istreambuf_iterator<unsigned char>());
	ASSERT_FALSE(XPackUnpacker::isPackedByXpack(sample));

	t = basic_ifstream<unsigned char>("testfiles/d104c8f148004ebf7e52fb5ca98f3e17/d104c8f148004ebf7e52fb5ca98f3e17", ios::binary);
	sample = ustring((istreambuf_iterator<unsigned char>(t)), istreambuf_iterator<unsigned char>());
	ASSERT_TRUE(XPackUnpacker::isPackedByXpack(sample));

}


TEST_F(XpackUnpackerTest, testAssemble)
{
	basic_ifstream<unsigned char> t("testfiles/d5b0a448f59c3e946255333ad0ef5cc5/d5b0a448f59c3e946255333ad0ef5cc5", ios::binary);
	ustring binary((istreambuf_iterator<unsigned char>(t)), istreambuf_iterator<unsigned char>());
	
	ustring dechunkedData = XPackUnpacker::assemble(binary);

	t = basic_ifstream<unsigned char>("testfiles/d5b0a448f59c3e946255333ad0ef5cc5/dechunked.bin", ios::binary);
	ustring dechunked((istreambuf_iterator<unsigned char>(t)), istreambuf_iterator<unsigned char>());

	ASSERT_EQ(dechunked, dechunkedData);
	
}


TEST_F(XpackUnpackerTest, testAssemble2)
{
	basic_ifstream<unsigned char> t("testfiles/d104c8f148004ebf7e52fb5ca98f3e17/d104c8f148004ebf7e52fb5ca98f3e17", ios::binary);
	ustring binary((istreambuf_iterator<unsigned char>(t)), istreambuf_iterator<unsigned char>());

	ustring dechunkedData = XPackUnpacker::assemble(binary);

	t = basic_ifstream<unsigned char>("testfiles/d104c8f148004ebf7e52fb5ca98f3e17/assembled.bin", ios::binary);
	ustring dechunked((istreambuf_iterator<unsigned char>(t)), istreambuf_iterator<unsigned char>());

	ASSERT_EQ(dechunked, dechunkedData);

}


TEST_F(XpackUnpackerTest, testDecryptFirstRound)
{
	basic_ifstream<unsigned char> t("testfiles/427b7b708de8436d73cbbfd645099416/1dechunked.bin", ios::binary);
	ustring data((istreambuf_iterator<unsigned char>(t)), istreambuf_iterator<unsigned char>());

	XPackUnpacker::decryptFirstRound(data);

	t = basic_ifstream<unsigned char>("testfiles/427b7b708de8436d73cbbfd645099416/2base64Revealed.bin", ios::binary);
	ustring realData((istreambuf_iterator<unsigned char>(t)), istreambuf_iterator<unsigned char>());

	ASSERT_EQ(data, realData);

}


TEST_F(XpackUnpackerTest, testDecryptFirstRound2)
{
	basic_ifstream<unsigned char> t("testfiles/d104c8f148004ebf7e52fb5ca98f3e17/assembled.bin", ios::binary);
	ustring data((istreambuf_iterator<unsigned char>(t)), istreambuf_iterator<unsigned char>());

	XPackUnpacker::decryptFirstRound(data);

	t = basic_ifstream<unsigned char>("testfiles/d104c8f148004ebf7e52fb5ca98f3e17/base64.bin", ios::binary);
	ustring realData((istreambuf_iterator<unsigned char>(t)), istreambuf_iterator<unsigned char>());

	ASSERT_EQ(data, realData);

}


TEST_F(XpackUnpackerTest, testSecondRoundAndDecompress)
{
	basic_ifstream<unsigned char> t("testfiles/d104c8f148004ebf7e52fb5ca98f3e17/revealedPt1.bin", ios::binary);
	ustring data((istreambuf_iterator<unsigned char>(t)), istreambuf_iterator<unsigned char>());

	data = XPackUnpacker::secondRoundAndDecompress(data);

	t = basic_ifstream<unsigned char>("testfiles/d104c8f148004ebf7e52fb5ca98f3e17/unpacked.bin", ios::binary);
	ustring realData((istreambuf_iterator<unsigned char>(t)), istreambuf_iterator<unsigned char>());

	ASSERT_EQ(data, realData);

}