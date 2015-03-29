var
  a,b,i,j:longint;
  o,p,q:qword;
function gcd(a,b:longint):longint;
begin
  if b=0 then exit(a);
  exit(gcd(b,a mod b));
end;
begin
  for i:=1 to 10 do
    begin
      o:=0;p:=1;q:=1;
      read(a,b);
      a:=gcd(a,b);
      for j:=3 to a do
        begin
          o:=p;p:=q;q:=int64(o+p);
        end;
      writeln(q);
    end;
  readln;readln;
end.