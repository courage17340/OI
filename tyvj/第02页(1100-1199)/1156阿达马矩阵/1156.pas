var
x,y,k:qword;
function ask(k,x,y:qword):longint;
begin
  if k=0 then exit(1);
  if(x<=exp(ln(2)*(k-1)))and(y<=exp(ln(2)*(k-1)))then exit(ask(k-1,x,y));
  if(x<=exp(ln(2)*(k-1)))and(y>exp(ln(2)*(k-1)))then exit(ask(k-1,x,y-trunc(exp(ln(2)*(k-1)))));
  if(x>trunc(exp(ln(2)*(k-1))))and(y<=exp(ln(2)*(k-1)))then exit(ask(k-1,x-trunc(exp(ln(2)*(k-1))),y));
  exit(1-ask(k-1,x-trunc(exp(ln(2)*(k-1))),y-trunc(exp(ln(2)*(k-1)))));
end;
begin
  read(k,x,y);
  writeln(ask(k,x,y));
end.