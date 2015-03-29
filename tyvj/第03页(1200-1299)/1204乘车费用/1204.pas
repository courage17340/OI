var
  n,m:longint;
  x,ans:real;
begin
  readln(n,m);
  if n=0 then ans:=0 else ans:=6;
  x:=n-2.5;
  if x>0 then if x<=7.5 then ans:=ans+x*1.2 else ans:=ans+7.5*1.2;
  x:=x-7.5;
  if x>0 then ans:=ans+1.8*x;
  m:=m div 5;
  ans:=ans+m;
  writeln(ans:0:0);
end.