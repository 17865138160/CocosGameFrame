/**
 *	@file	LUtils.h
 *	@date	2018/12/17
 *
 * 	@author lujun
 *	Contact:(QQ:495904500)
 *	
 *	@brief	������
 */

#ifndef __LUTILS_20181217045610_H
#define __LUTILS_20181217045610_H

#include "cocos2d.h"

USING_NS_CC;

namespace L {

/**
*	@brief ·���ָ�
*	@details ��linux·����ʽ,�ַ�'/'����'\'��������Ϊ·���ָ�����
*		������·���ָ��п��Դ��ڶ��·���ָ���
*/
class PathSplit {
protected:

	/**
	*	����·��
	*/
	bool			m_isabsolute;

	/*
	 *	�����ָ���
	 */
	bool			m_isendsepa;

	/**
	*	�ָ���·��
	*	���·�������ڲ�����
	*/
	std::string		m_path;

	/**
	*	�ָǰ���λ��
	*/
	const char*		m_cursor;

	/**
	*	�ָ����λ��
	*/
	const char*		m_endpos;

public:

	/**
	*	@brief ��ָ��·������·���ָ�
	*	@param[in]	path	ָ����·��(����ΪNULL����Ӧ·��Ϊ"")
	*/
	PathSplit(const char *path);

	/**
	*	@brief ������·���ָ�
	*/
	virtual ~PathSplit() {}

	/**
	*	@brief ���Ե�ǰ·���ָ����Ƿ��Ǿ���·��
	*	@return �����Ƿ�ɹ�
	*/
	bool is_absolute_path();

	/*
	 *	�����ָ���
	 */
	bool is_end_separate();

	/**
	*	@brief ����·���ָǰ���
	*/
	void reset_cursor();

	/**
	*	@brief ����·���ָǰ��꣬��ȡ��һ��·���ڵ�
	*	@return ·���ڵ�
	*	@retval	NULL ·���ָ����
	*/
	const char* get_next();
};

CC_DLL std::string standardPath(const std::string &path);

CC_DLL void XOR_encrypt(std::string &data, const std::string &xorkey);

CC_DLL bool AES_encrypt(const unsigned char* aeskey, const unsigned char* aesiv, const unsigned char *inbuff, size_t insize, unsigned char *outbuff, size_t &outsize);

CC_DLL bool AES_decrypt(const unsigned char* aeskey, const unsigned char* aesiv, const unsigned char *inbuff, size_t insize, unsigned char *outbuff, size_t &outsize);

CC_DLL bool RSA_publicEncrypt(const unsigned char* data, int dlen, std::string &encdata, const std::string &pubfile);

CC_DLL bool RSA_publicDecrypt(const unsigned char* data, int dlen, std::string &encdata, const std::string &pubfile);

CC_DLL bool RSA_privateEncrypt(const unsigned char* data, int dlen, std::string &decdata, const std::string &prifile);

CC_DLL bool RSA_privateDecrypt(const unsigned char* data, int dlen, std::string &decdata, const std::string &prifile);

CC_DLL bool Zlib_compress(const char *uncdata, size_t unclen, std::string &cmpdata);

CC_DLL bool Zlib_uncompress(const char *cmpdata, size_t cmplen, size_t unclen, std::string &uncdata);

CC_DLL void mergeFile(const std::string &indir, const std::string &outfile, const std::string &infmt, bool iszlib);

CC_DLL bool patchH(const std::string &newfile, const std::string &oldfile, const std::string &difffile,int bufsize = 10240);

CC_DLL bool unzip(const std::string &zipPath, const std::string &filePath, const std::string &outPath);
    
CC_DLL bool copyFile(const std::string &srcPath, const std::string &destPath);

}

#endif //!__LUTILS_20181217045610_H
