var
  i,n,ans:longint;
  x,y:array[0..1000] of longint;
begin
  readln(n);
  ans:=0;
  for i:=1 to n do
    read(x[i],y[i]);
  x[n+1]:=x[1];y[n+1]:=y[1];
  for i:=1 to n do
    ans:=ans+x[i]*y[i+1]-y[i]*x[i+1];
  ans:=ans div 2;
  writeln(ans);
end.