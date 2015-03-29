type rec=array[1..100] of longint;
var
  f:array[0..1000] of rec;
  n,i,j,k:longint;
procedure add(x,y:longint);
var
  i,j:longint;
begin
  for i:=1 to 100 do
    f[x,i]:=f[x,i]+f[y,i];
  j:=0;
  for i:=100 downto 1 do
    begin
      f[x,i]:=f[x,i]+j;
      j:=f[x,i] div 10;
      f[x,i]:=f[x,i] mod 10;
    end;
end;
procedure print(x:longint);
var
  i,j:longint;
begin
  j:=1;
  while f[x,j]=0 do inc(j);
  for i:=j to 100 do write(f[x,i]);
  writeln;
end;
begin
  fillchar(f,sizeof(f),0);
  readln(n,k);
  f[0,100]:=1;
  for i:=1 to k do
    for j:=i to n do
      add(j,j-i);
  print(n);
end.