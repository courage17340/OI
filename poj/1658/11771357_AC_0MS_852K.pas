var
  a,b,c,d,n,i:longint;
begin
  readln(n);
  for i:=1 to n do
    begin
      readln(a,b,c,d);
      write(a,' ',b,' ',c,' ',d,' ');
      if (a-b=b-c)and(b-c=c-d) then
        begin
          writeln(d+d-c);
          continue;
        end;
      writeln(d div c*d);
    end;
end.