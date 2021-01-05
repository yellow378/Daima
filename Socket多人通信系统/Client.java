package com;
import java.io.*;
import java.util.*;
import java.net.*;

public class Client{
	static String name;											//客户端的昵称
	static boolean con_state = false;							//是否连接
	static ArrayList<String> list = new ArrayList<String>();	//维护的通讯录
	public static void main(String[] args) {
		try {
			Scanner reader = new Scanner(System.in);
			System.out.println("请输入昵称");
			name = reader.next();
			Socket client = new Socket("127.0.0.1",1515);		//建立TCP连接
			Client.list.add("ALL");
			new Thread(new ClientIn(client)).start();			//接收数据的线程
			new Thread(new ClientOut(client)).start();			//发送数据的线程
		} catch (IOException e) {
		}
	}
	static void showMates() {									//打印通讯录
		System.out.println("+++++++++++++++++++++++++");
		System.out.println("+--------通讯录--------\t+");
		int i = 0;
		for(String t:Client.list) {
			if(t.equals(Client.name)) {
				System.out.println("+"+i+++"\t"+t+"  <--我自己\t+");
			}else {
				System.out.println("+"+i+++"\t"+t+"\t\t+");
			}
		}
		System.out.println("+----------------------\t+");
		System.out.println("+输入格式：序号+信息\t+");
		System.out.println("+退出格式： 0 +endend\t+");
		System.out.println("+++++++++++++++++++++++++");
	}
}
//接收的线程
class ClientIn implements Runnable{
	Socket socket;
	ClientIn(Socket socket){
		this.socket = socket;
	}
	public void run() {
		try {
			ObjectInputStream objectIn = new ObjectInputStream(socket.getInputStream());
			while(true) {
				Send t = (Send)objectIn.readObject();
				switch(t.type) {
				case 1:{
					//发来的是信息，打印信息
					if(Client.name.equals(t.to) || "ALL".equals(t.to)) {
						if("ALL".equals(t.to)) {
							System.out.print("(ALL) ");
						}
						System.out.println(t.from + ":"+ t.message);
					}
					break;
				}
				case 4:{
					//发来的是增加用户的通知，添加用户
					if(!Client.list.contains(t.message)) {
						Client.list.add(t.message);
						Client.showMates();
					}
					break;
				}
				case 5:{
					//发来的是删除用户的通知，删除用户
					if(Client.list.contains(t.message)) {
						Client.list.remove(t.message);
						Client.showMates();
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
//发送的线程
class ClientOut implements Runnable{
	Socket socket;
	Scanner reader = new Scanner(System.in);
	ClientOut(Socket socket){
		this.socket = socket;
	}
	public void run() {
		try {
			OutputStream out = socket.getOutputStream();
			ObjectOutputStream objectOut = new ObjectOutputStream(out);
			//连接时，发送连接的请求，表明身份，加入通信名单
			if(Client.con_state == false) {
				Send t = new Send("建立连接");
				t.type = 2;
				t.from = Client.name;
				t.to = "ALL";
				objectOut.writeObject(t);
				Client.con_state = true;
			}
			while(true) {
				//输入序号和信息
				int to = reader.nextInt();
				String string  = reader.nextLine();
				if(to >= Client.list.size()) {
					System.out.println("请输入正确序号：");
					continue;
				}
				//发送释放的请求，从通信名单中删除
				if(" endend".equals(string)) {
					Send t = new Send("释放连接");
					t.type = 3;
					t.from = Client.name;
					t.to = "ALL";
					objectOut.writeObject(t);
					Client.con_state = false;
					break;
				}
				//发送普通信息
				else {
					Send t = new Send(string);
					t.type = 1;
					t.from = Client.name;
					t.to = Client.list.get(to);
					objectOut.writeObject(t);
				}
			}
			socket.close();
		} catch (IOException e) {
		}
	}
	
}