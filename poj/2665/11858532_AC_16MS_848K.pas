var
  n,i,j,L,x,y,ans:longint;
begin
  while true do
    begin
      readln(L,n);
      if L+n=0 then break;
      ans:=L+1;
      for i:=1 to n do
        begin
          readln(x,y);
          ans:=ans-(y-x+1);
        end;
      writeln(ans);
    end;
end.