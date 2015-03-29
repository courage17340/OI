var
  a,b,c,d,x1,x2,x3,p,q,t:extended;
function f(x:extended):extended;
begin
  exit(x*x*x+b*x*x+c*x+d);
end;
begin
  readln(a,b,c,d);
  b:=b/a;c:=c/a;d:=d/a;
  a:=1;
  p:=-100;
  q:=100;
  x1:=0;
  while q-p>=1e-3 do
    begin
      if f(p)*f(x1)<=0 then q:=x1 else p:=x1;
      x1:=(p+q)/2;
    end;
  a:=1;
  c:=x1*x1+x1*b+c;
  b:=x1+b;
  d:=b*b-4*a*c;
  x2:=(-b+sqrt(d))/(2*a);
  x3:=(-b-sqrt(d))/(2*a);
  if x2<x1 then begin t:=x1;x1:=x2;x2:=t;end;
  if x3<x2 then begin t:=x2;x2:=x3;x3:=t;end;
  if x2<x1 then begin t:=x1;x1:=x2;x2:=t;end;
  writeln(x1:0:2,' ',x2:0:2,' ',x3:0:2);
end.