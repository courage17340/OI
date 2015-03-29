var
  a,b:array[1..2000] of longint;
  s:ansistring;
  g:array[0..2000,0..2000] of longint;
  la,lb,i,j,k,t:longint;
begin
  la:=0;lb:=0;
  readln(s);la:=length(s);
  for i:=1 to la do a[i]:=ord(s[i]);
  readln(s);lb:=length(s);
  for i:=1 to lb do b[i]:=ord(s[i]);
  read(k);
  g[0,0]:=0;
  for i:=1 to la do g[i,0]:=k+g[i-1,0];
  for j:=1 to lb do g[0,j]:=k+g[0,j-1];
  for i:=1 to la do
    for j:=1 to lb do
      begin
        g[i,j]:=k+g[i-1,j];
        t:=k+g[i,j-1];
        if g[i,j]>t then g[i,j]:=t;
        t:=abs(a[i]-b[j])+g[i-1,j-1];
        if g[i,j]>t then g[i,j]:=t;
      end;
  writeln(g[la,lb]);
end.
