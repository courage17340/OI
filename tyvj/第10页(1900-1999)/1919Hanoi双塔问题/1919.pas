const
  max=10000;
var
  a:array[1..max] of integer;
  i,j,k,n,jw,x:longint;
procedure init;
begin
  readln(n);
end;
procedure work;
begin
  fillchar(a,sizeof(a),0);
  a[max]:=2;
  k:=max;
  for i:=2 to n do
    begin
      jw:=0;
      a[max]:=a[max]+1;
      for j:=max downto k do
        begin
          x:=a[j]*2;
          a[j]:=x mod 10+jw;
          jw:=x div 10;
        end;
      if jw>0 then
        begin
          k:=k-1;
          a[k]:=jw;
        end;
    end;
  for i:=k to max do write(a[i]);
end;
begin{main}
  init;
  work;
end.