var
  i,n:longint;
  x,f,g,f1,g1:extended;
function max(a,b:extended):extended;
begin
  max:=a;
  if a<b then max:=b;
end;
begin
  readln(n);
  f1:=1;
  g1:=0;
  for i:=1 to n do
    begin
      readln(x);
      f:=f1;
      g:=g1;
      f:=max(f,g1*x);
      g:=max(g,f1/x);
      f1:=f;
      g1:=g;
    end;
  writeln(f1:0:0);
end.