var
  a,b,c,t,ans,n,i:longint;
begin
  read(n);
  if n=1 then begin writeln(1);halt;end;
  read(b,c);
  t:=0;
  for i:=3 to n do
    begin
      a:=b;b:=c;
      read(c);
      if (a<b)and(c<b) or (a>b)and(c>b) then inc(t);
    end;
  if t=0 then t:=-1;
  ans:=t+2;
  writeln(ans);
  readln;readln;
end.