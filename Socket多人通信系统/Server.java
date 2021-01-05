package com;

import java.io.IOException;
import java.io.*;
import java.net.*;
import java.util.HashMap;
import java.util.Scanner;

public class Server{
	static ServerSocket serverSocket;															//serverSocket
	static HashMap<String,ObjectOutputStream> map = new HashMap<String,ObjectOutputStream>();	//维护的哈希表 <昵称，对象输出流>
	public static void main(String[] args) {
		try {
			serverSocket = new ServerSocket(1515);
			while(true) {
				Socket accept_client = serverSocket.accept(); 			//接收连接
				new Thread(new ServerIn(accept_client)).start();		//增加接收的线程
			}
		} catch (IOException e) {
		}
	}
}
//接受的线程
class ServerIn implements Runnable{
	Socket socket;
	ServerIn(Socket socket){
		this.socket = socket;
	}
	public void run() {
		try {
			ObjectInputStream objectIn = new ObjectInputStream(socket.getInputStream());
			while(true) {
				//接收信息
				Send t = (Send)objectIn.readObject();
				//打印信息
				System.out.println("from:"+t.from+" to: "+ t.to+" 类型： "+ t.type+" 信息： "+t.message);
				switch(t.type) {
				//普通信息，转发
				case 1:{
					//广播，发给所有人，不用修改对象
					if("ALL".equals(t.to)) {
						for(var i:Server.map.keySet()) {
							ObjectOutputStream objectout = Server.map.get(i);
							objectout.writeObject(t);
						}
					}
					//发给某个人，不用修改对象
					else {
						if(Server.map.containsKey(t.to)) {
							ObjectOutputStream objectout = Server.map.get(t.to);
							objectout.writeObject(t);
						}
					}
					break;
				}
				//增加用户
				case 2:{
					if(Server.map.containsKey(t.from)) {
						Server.map.remove(t.from);
					}
					ObjectOutputStream objectOut = new ObjectOutputStream(socket.getOutputStream());
					//新来的用户发送原来的用户信息
					for(var i:Server.map.keySet()) {
						Send s = new Send(i);
						s.from = "ALL";
						s.to = t.from;
						s.type = 4;
						objectOut.writeObject(s);
					}
					//map增加新的键值对
					Server.map.put(t.from, objectOut);
					//给原来的每个用户发送新用户信息
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
				//删除用户
				case 3:{
					//map删除键值对
					if(Server.map.containsKey(t.from)) {
						Server.map.remove(t.from);
					}
					//通知每个原来的用户删除用户的信息
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