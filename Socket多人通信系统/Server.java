package com;

import java.io.IOException;
import java.io.*;
import java.net.*;
import java.util.HashMap;
import java.util.Scanner;

public class Server{
	static ServerSocket serverSocket;															//serverSocket
	static HashMap<String,ObjectOutputStream> map = new HashMap<String,ObjectOutputStream>();	//ά���Ĺ�ϣ�� <�ǳƣ����������>
	public static void main(String[] args) {
		try {
			serverSocket = new ServerSocket(1515);
			while(true) {
				Socket accept_client = serverSocket.accept(); 			//��������
				new Thread(new ServerIn(accept_client)).start();		//���ӽ��յ��߳�
			}
		} catch (IOException e) {
		}
	}
}
//���ܵ��߳�
class ServerIn implements Runnable{
	Socket socket;
	ServerIn(Socket socket){
		this.socket = socket;
	}
	public void run() {
		try {
			ObjectInputStream objectIn = new ObjectInputStream(socket.getInputStream());
			while(true) {
				//������Ϣ
				Send t = (Send)objectIn.readObject();
				//��ӡ��Ϣ
				System.out.println("from:"+t.from+" to: "+ t.to+" ���ͣ� "+ t.type+" ��Ϣ�� "+t.message);
				switch(t.type) {
				//��ͨ��Ϣ��ת��
				case 1:{
					//�㲥�����������ˣ������޸Ķ���
					if("ALL".equals(t.to)) {
						for(var i:Server.map.keySet()) {
							ObjectOutputStream objectout = Server.map.get(i);
							objectout.writeObject(t);
						}
					}
					//����ĳ���ˣ������޸Ķ���
					else {
						if(Server.map.containsKey(t.to)) {
							ObjectOutputStream objectout = Server.map.get(t.to);
							objectout.writeObject(t);
						}
					}
					break;
				}
				//�����û�
				case 2:{
					if(Server.map.containsKey(t.from)) {
						Server.map.remove(t.from);
					}
					ObjectOutputStream objectOut = new ObjectOutputStream(socket.getOutputStream());
					//�������û�����ԭ�����û���Ϣ
					for(var i:Server.map.keySet()) {
						Send s = new Send(i);
						s.from = "ALL";
						s.to = t.from;
						s.type = 4;
						objectOut.writeObject(s);
					}
					//map�����µļ�ֵ��
					Server.map.put(t.from, objectOut);
					//��ԭ����ÿ���û��������û���Ϣ
					for(var i:Server.map.keySet()) {
						ObjectOutputStream objectout = Server.map.get(i);
						Send s = new Send(t.from);
						s.from = "ALL";
						s.to = i;
						s.type = 4;
						objectout.writeObject(s);
					}
					break;
				}
				//ɾ���û�
				case 3:{
					//mapɾ����ֵ��
					if(Server.map.containsKey(t.from)) {
						Server.map.remove(t.from);
					}
					//֪ͨÿ��ԭ�����û�ɾ���û�����Ϣ
					for(var i:Server.map.keySet()) {
						ObjectOutputStream objectout = Server.map.get(i);
						Send s = new Send(t.from);
						s.from = "ALL";
						s.to = i;
						s.type = 5;
						objectout.writeObject(s);
					}
					break;
				}
				}
			}
		} catch (IOException e) {
		} catch (ClassNotFoundException e) {
		}
	}
	
}