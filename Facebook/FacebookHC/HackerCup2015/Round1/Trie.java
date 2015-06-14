import java.io.*;
import java.util.*;
public class Trie{
//public class Trie{
private Trie[] hijos=new Trie[26];
// hijos=new Trie[26];
private boolean last;
private int aux;
public Trie(){
last=false;
aux=0;
for(int i=0; i < 26; ++i)
hijos[i]=null;
}
//}
public static void insert(Trie v,String cad,int i){
v.aux++;
if(i==cad.length())
v.last=true;
else{
int k=cad.charAt(i)-'a';
if(v.hijos[k]==null){
v.hijos[k]=new Trie();
}
insert(v.hijos[k],cad,i+1);
}
}

public static boolean Buscar(Trie v,String cad,int i){
if(i==cad.length())
return true;
else{
int k=cad.charAt(i)-'a';
if(v.hijos[k]==null){
return false;
}
return Buscar(v.hijos[k],cad,i+1);
}
}

public static int solve(Trie v,String cad,int i){
if(i==cad.length() || v.aux==1)
return 0;
else{
int k=cad.charAt(i)-'a';
return solve(v.hijos[k],cad,i+1) + 1;
}

}
public static void main(String ... args) throws Exception{
BufferedReader scan=new BufferedReader(new InputStreamReader(System.in));
int T,n,c,auc;
String linea;
Trie verga=new Trie();
String aux;
linea=scan.readLine();
T=Integer.parseInt(linea);
for(int lol=1; lol<=T; lol++){
linea=scan.readLine();
n=Integer.parseInt(linea);
String vec[]=new String[n];
for (int i=0; i<n;i++){
vec[i]=scan.readLine();
}
c=0;
Trie t=new Trie();
for(int i=0;i<n;i++){
aux="";
auc=0;
insert(t,vec[i],0);
auc=solve(t,vec[i],0);
c+=auc;
}
System.out.println("Case #"+lol+": "+(c+1));
}
}
}