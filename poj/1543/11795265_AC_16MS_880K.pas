var
  n,x,y,z,d:longint;
begin
  readln(n);
  for d:=6 to n do
    begin
      for x:=2 to d-1 do
        begin
          if x*x*x*3>=d*d*d then break;
          for y:=x to d-1 do
            if x*x*x+y*y*y*2<=d*d*d then
              for z:=y to d-1 do
                if x*x*x+y*y*y+z*z*z=d*d*d then
                  begin
                    writeln('Cube = ',d,', Triple = (',x,',',y,',',z,')');
                    break;
                  end;
        end;
    end;
end.