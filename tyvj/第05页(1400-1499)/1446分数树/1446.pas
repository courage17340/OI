var
  l1,l2,r1,r2,m1,m2,n,x,y,i:longint;
function chu(a,b:longint):extended;
begin
  if b=0 then exit(maxlongint);
  chu:=a/b;
end;
begin
  read(n);
  for i:=1 to n do
    begin
      read(x,y);
      l1:=0;l2:=1;r1:=1;r2:=0;
      repeat
        m1:=l1+r1;
        m2:=l2+r2;
        if chu(m1,m2)=chu(x,y) then break;
        if chu(x,y)>chu(m1,m2) then begin write('R');l1:=m1;l2:=m2;end;
        if chu(x,y)<chu(m1,m2) then begin write('L');r1:=m1;r2:=m2;end;
        until false;
      writeln;
    end;
end.