/// \file		WnRingBuffer.h
/// \brief		WIND���λ�������������ļ�
/// \author		����ѫ
/// \version	1.0
/// \date		2011-07-19
/// \history	2011-07-19 �½�

#pragma once

/// \brief WIND���λ�������
class WnRingBuffer
{
public:
	/// \brief ���캯��
	/// \param unSize ��������С
	WnRingBuffer(unsigned int unSize);
	/// \brief ��������
	~WnRingBuffer(void);

	/// \brief ��ȡд����
	/// \param pbWrite дָ��
	/// \param unEnableSize ��д��С
	void GetWriteParam(unsigned char*& pbWrite, unsigned int& unEnableSize);

	/// \brief ��ȡ������
	/// \param pbRead ��ָ��
	/// \param unEnableSize �ɶ���С
	void GetReadParam(const unsigned char*& pbRead, unsigned int& unEnableSize);

	/// \brief ����дλ��
	/// \param unWriteBytes ��д���ֽ���
	void UpdateWritePos(unsigned int unWriteBytes);

	/// \brief ���¶�λ��
	/// \param unWritedBytes �¶����ֽ���
	void UpdateReadPos(unsigned int unReadBytes);

private:
	// ��������С
	unsigned int m_unBufferSize;

	// ������
	unsigned char *m_pbBuffer;

	// д��ָ��
	unsigned char *m_pbWrite;

	// ��ȡָ��
	unsigned char *m_pbRead;

	// ��д����ֽ���
	unsigned __int64 m_ullWriteCount;

	// �Ѷ������ֽ���
	unsigned __int64 m_ullReadCount;

	// ��������
	boost::mutex m_oMutex;
};
