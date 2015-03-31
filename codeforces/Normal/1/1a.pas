var
  n,m,a,p,q:longint;
begin
  readln(n,m,a);
  p:=n div a;
  if n mod a<>0 then inc(p);
  q:=m div a;
  if m mod a<>0 then inc(q);
  writeln(int64(p)*int64(q));
  readln;
end.