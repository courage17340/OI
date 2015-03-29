var
  a:array[0..1000] of longint;
  f:array[-1..41,-1..41,-1..41,-1..41] of longint;
  b:array[1..4] of longint;
  count,n,m:longint;
procedure init;
var
  i,j:longint;
begin
  readln(n,m);
  count:=0;
  fillchar(a,sizeof(a),0);
  fillchar(f,sizeof(f),0);
  fillchar(b,sizeof(b),0);
  for i:=1 to n do read(a[i]);
  readln;
  for i:=1 to m do
    begin
      read(j);
      inc(b[j]);
    end;
end;
function max(a,b,c,d:longint):Longint;
begin
  max:=a;
  if max<b then max:=b;
  if max<c then max:=c;
  if max<d then max:=d;
end;
procedure work;
var
  i,j,k,p,q:longint;
begin
  for i:=0 to b[1] do
    for j:=0 to b[2] do
      for p:=0 to b[3] do
        for q:=0 to b[4] do
          f[i,j,p,q]:=max(f[i-1,j,p,q],f[i,j-1,p,q],f[i,j,p-1,q],f[i,j,p,q-1])+a[1+i+2*j+3*p+4*q];
  writeln(f[b[1],b[2],b[3],b[4]]);
end;
begin
  init;
  work;
end.