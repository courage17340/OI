var
  a:array[1..100000] of boolean;
  n,i,j,k,p,q,m,r,s,pp,qq:longint;
function min(a,b:longint):longint;
begin
  min:=a;
  if a>b then min:=b;
end;
begin
  fillchar(a,sizeof(a),true);
  a[1]:=false;
  i:=1;
  while i<=trunc(sqrt(100000)) do
    begin
      while not a[i] do inc(i);
      for j:=2 to 100000 div i do a[i*j]:=false;
      inc(i);
    end;
  while true do
    begin
      readln(m,r,s);
      pp:=2;qq:=2;
      if m=0 then break;
      for p:=trunc(sqrt(m)) downto 2 do if a[p] then
        begin
          for q:=min(m div p,p*s div r) downto p do if a[q] then
            begin
              if pp*qq<p*q then begin pp:=p;qq:=q;end;
              break;
            end;
        end;
       writeln(pp,' ',qq);
    end;
end.