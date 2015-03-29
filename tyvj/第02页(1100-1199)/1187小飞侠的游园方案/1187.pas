var
  t,v:array[0..100] of longint;
  f:array[0..100,0..1000] of longint;
  time,m,i,j:longint;
procedure init;
begin
  readln(m,time);
  fillchar(t,sizeof(t),0);
  fillchar(v,sizeof(v),0);
  fillchar(f,sizeof(f),0);
  for i:=1 to m do
    readln(v[i],t[i]);
end;
function max(a,b:longint):longint;
begin
  max:=a;
  if max<b then max:=b;
end;
procedure work;
begin
  for i:=1 to m do
    for j:=1 to time do
      begin
        f[i,j]:=f[i-1,j];
        if j>=t[i] then f[i,j]:=max(f[i,j],f[i-1,j-t[i]]+v[i]);
      end;
  write(f[m,time]);
end;
begin
  init;
  work;
end.
