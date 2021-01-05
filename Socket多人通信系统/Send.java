package com;

import java.io.Serializable;

public class Send implements Serializable{
	private static final long serialVersionUID = 1L;
	int type;
	/*
	 * 1. 发送信息
	 * 2. 通知服务器连接
	 * 3. 通知服务器断开
	 * 4. 通知客户端增加用户
	 * 5. 通知客户端删除用户
	 */
	String from;
	/*
	 * 来自哪里
	 */
	String to;
	/*
	 * 发到哪里
	 * type==2:to为ALL，发给Server，建立连接，服务器向其他客户端发送新添加的用户，向from发送本来的用户
	 * type==3:to为ALL，发送给SErver，释放连接，向其他用户通知to离开
	 */
	String message;
	/*
	 * 信息
	 */
	Send(String message){		//构造函数，放入信息
		this.message = message;
	}

}
