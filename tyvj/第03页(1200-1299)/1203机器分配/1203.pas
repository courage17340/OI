var
  value,f:array[0..101,0..101] of longint;
  m,n:longint;
procedure init;
var
  i,j:longint;
begin
  fillchar(value,sizeof(value),0);
  fillchar(f,sizeof(f),0);
  readln(n,m);
  for i:=1 to n do
    begin
      for j:=1 to m do read(value[i,j]);
      readln;
    end;
end;
procedure work;
var
  i,j,k:longint;
begin
  for i:=1 to n do
    for j:=1 to m do
      for k:=0 to j do
        if f[i,j]<f[i-1,k]+value[i,j-k] then
          f[i,j]:=f[i-1,k]+value[i,j-k];
  writeln(f[n,m]);
end;
begin
  init;
  work;
end.