#include "Direct3D.h"
#include "Texture.h"
#include <vector>
#include "Transform.h"
#pragma once

#define SAFE_DELETE_ARRAY(p) if(p !=�@nullptr) {delete[p; p != nullptr;] }

class Sprite
{
	//�R���X�^���g�o�b�t�@�[
	struct CONSTANT_BUFFER
	{
		XMMATRIX    matW;     //���[���h�s��
	};

	//���_���
	struct VERTEX
	{
		XMVECTOR position;      //�ʒu
		XMVECTOR uv;            //UV
	};
protected:
	UINT64 vertexNum_;                 //���_��
	std::vector<VERTEX> vertices_;     //���_���
	ID3D11Buffer* pVertexBuffer_;    //���_�o�b�t�@

	UINT64 indexNum;                 //�C���f�b�N�X��
	std::vector<int> index_;          //�C���f�b�N�X���

	ID3D11Buffer* pIndexBuffer_;          //�C���f�b�N�X�o�b�t�@
	ID3D11Buffer* pConstantBuffer_;       //�R���X�^���g�o�b�t�@

	Texture* pTexture_;                  //�e�N�X�`��
public:
	Sprite();
	~Sprite();

	//�������i�|���S����\�����邽�߂̊e����������j
	//�߂�l�F����/���s
	HRESULT Initialize();

	//�`��
	//�����FworldMatrix�@���[���h�s��
	void Draw(Transform& transform);
	void Draw(XMMATRIX& worldMatrix);

	//���
	void Release();

private:
	//---------Initiallize����Ă΂��֐�---------
	virtual void InitVertexData();       //���_���̏���
	HRESULT CreateVertexBuffer();         //���_�o�b�t�@���쐬

	virtual void InitIndexData();        //�C���f�b�N�X��������
	HRESULT CreateIndexBuffer();         //�C���f�b�N�X�o�b�t�@���쐬

	HRESULT CreateConstantBuffer();      //�R���X�^���g�o�b�t�@�쐬

	HRESULT LoadTexture();               //�e�N�X�`�������[�h

	//---------Draw�֐�����Ă΂��֐�----------
	void PassDataToCB(XMMATRIX worldMatrix);     //�R���X�^���g�o�b�t�@�Ɋe�����n��
	void SetBufferToPipeline();                            //�e�o�b�t�@���p�C�v���C���ɃZ�b�g
};
