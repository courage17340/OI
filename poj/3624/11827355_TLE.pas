var
  w,v:array[1..4000] of longint;
  f:array[1..2,0..13000] of longint;
  t1,t2,t,n,m,i,j:longint;
function max(a,b:longint):longint;
begin
  max:=a;
  if a<b then max:=b;
end;
begin
  fillchar(f,sizeof(f),0);
  readln(n,m);
  for i:=1 to n do readln(w[i],v[i]);
  t1:=1;
  t2:=2;
  for i:=1 to n do
    begin
      t:=t1;t1:=t2;t2:=t;
      for j:=0 to m do
        begin
          f[t2,j]:=f[t1,j];
          if j>=w[i] then f[t2,j]:=max(f[t2,j],f[t1,j-w[i]]+v[i]);
        end;
    end;
  writeln(f[t2,m]);
end.