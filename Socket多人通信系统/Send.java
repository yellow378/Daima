package com;

import java.io.Serializable;

public class Send implements Serializable{
	private static final long serialVersionUID = 1L;
	int type;
	/*
	 * 1. ������Ϣ
	 * 2. ֪ͨ����������
	 * 3. ֪ͨ�������Ͽ�
	 * 4. ֪ͨ�ͻ��������û�
	 * 5. ֪ͨ�ͻ���ɾ���û�
	 */
	String from;
	/*
	 * ��������
	 */
	String to;
	/*
	 * ��������
	 * type==2:toΪALL������Server���������ӣ��������������ͻ��˷�������ӵ��û�����from���ͱ������û�
	 * type==3:toΪALL�����͸�SErver���ͷ����ӣ��������û�֪ͨto�뿪
	 */
	String message;
	/*
	 * ��Ϣ
	 */
	Send(String message){		//���캯����������Ϣ
		this.message = message;
	}

}
