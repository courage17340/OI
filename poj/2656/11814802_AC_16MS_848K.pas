var
  a:array[1..7] of longint;
  n,i,j,k,x,y:longint;
begin
  while true do
    begin
      readln(n);
      if n=0 then break;
      j:=0;k:=0;
      for i:=1 to n do
        begin
          readln(x,y);
          a[i]:=x+y-8;
        end;
      for i:=1 to n do
        if j<a[i] then
          begin
            j:=a[i];
            k:=i;
          end;
      writeln(k);
    end;
end.