package com;
import java.io.*;
import java.util.*;
import java.net.*;

public class Client{
	static String name;											//�ͻ��˵��ǳ�
	static boolean con_state = false;							//�Ƿ�����
	static ArrayList<String> list = new ArrayList<String>();	//ά����ͨѶ¼
	public static void main(String[] args) {
		try {
			Scanner reader = new Scanner(System.in);
			System.out.println("�������ǳ�");
			name = reader.next();
			Socket client = new Socket("127.0.0.1",1515);		//����TCP����
			Client.list.add("ALL");
			new Thread(new ClientIn(client)).start();			//�������ݵ��߳�
			new Thread(new ClientOut(client)).start();			//�������ݵ��߳�
		} catch (IOException e) {
		}
	}
	static void showMates() {									//��ӡͨѶ¼
		System.out.println("+++++++++++++++++++++++++");
		System.out.println("+--------ͨѶ¼--------\t+");
		int i = 0;
		for(String t:Client.list) {
			if(t.equals(Client.name)) {
				System.out.println("+"+i+++"\t"+t+"  <--���Լ�\t+");
			}else {
				System.out.println("+"+i+++"\t"+t+"\t\t+");
			}
		}
		System.out.println("+----------------------\t+");
		System.out.println("+�����ʽ�����+��Ϣ\t+");
		System.out.println("+�˳���ʽ�� 0 +endend\t+");
		System.out.println("+++++++++++++++++++++++++");
	}
}
//���յ��߳�
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
					//����������Ϣ����ӡ��Ϣ
					if(Client.name.equals(t.to) || "ALL".equals(t.to)) {
						if("ALL".equals(t.to)) {
							System.out.print("(ALL) ");
						}
						System.out.println(t.from + ":"+ t.message);
					}
					break;
				}
				case 4:{
					//�������������û���֪ͨ������û�
					if(!Client.list.contains(t.message)) {
						Client.list.add(t.message);
						Client.showMates();
					}
					break;
				}
				case 5:{
					//��������ɾ���û���֪ͨ��ɾ���û�
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
//���͵��߳�
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
			//����ʱ���������ӵ����󣬱�����ݣ�����ͨ������
			if(Client.con_state == false) {
				Send t = new Send("��������");
				t.type = 2;
				t.from = Client.name;
				t.to = "ALL";
				objectOut.writeObject(t);
				Client.con_state = true;
			}
			while(true) {
				//������ź���Ϣ
				int to = reader.nextInt();
				String string  = reader.nextLine();
				if(to >= Client.list.size()) {
					System.out.println("��������ȷ��ţ�");
					continue;
				}
				//�����ͷŵ����󣬴�ͨ��������ɾ��
				if(" endend".equals(string)) {
					Send t = new Send("�ͷ�����");
					t.type = 3;
					t.from = Client.name;
					t.to = "ALL";
					objectOut.writeObject(t);
					Client.con_state = false;
					break;
				}
				//������ͨ��Ϣ
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