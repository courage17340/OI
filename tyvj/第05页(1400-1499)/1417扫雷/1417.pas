const
  x:array[1..8] of longint=(-1,-1,-1,0,0,1,1,1);
  y:array[1..8] of longint=(-1,0,1,-1,1,-1,0,1);
var
  a:array[0..1010,0..1010] of longint;
  f:array[0..1010,0..1010] of boolean;
  i,j,m,n,ans:longint;
  ch:char;
function sum:longint;
var k:longint;
begin
  sum:=0;
  for k:=1 to 8 do if a[i+x[k],j+y[k]]=-1 then inc(sum);
end;
procedure work(i,j:longint);
var k:longint;
begin
  if (i=0)or(j=0)or(i=n+1)or(j=m+1) then exit;
  f[i,j]:=true;
  for k:=1 to 8 do
    if not f[i+x[k],j+y[k]] then
      if a[i+x[k],j+y[k]]=0 then work(i+x[k],j+y[k]) else f[i+x[k],j+y[k]]:=true;
end;
begin
  ans:=0;
  readln(n,m);
  fillchar(a,sizeof(a),0);
  fillchar(f,sizeof(f),false);
  for i:=1 to n do
    begin
      for j:=1 to m do begin read(ch);if ch='*' then dec(a[i,j]);end;
      readln;
    end;
  for i:=1 to n do
    for j:=1 to m do
      if a[i,j]=0 then a[i,j]:=sum;
  for i:=1 to n do
    for j:=1 to m do
      if (a[i,j]=0)and(not f[i,j]) then
        begin
          work(i,j);
          inc(ans);
        end;
  for i:=1 to n do
    for j:=1 to m do
      if (a[i,j]>0)and(not f[i,j]) then inc(ans);
  writeln(ans);
end.